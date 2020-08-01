#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string filename_a = "logs.txt";
std:: string filename_b= "list.txt";
std::string path = "E:/ss files/Exxon/";
int argNum;
std::vector<std::string> logArgs;
void logWriter() 
{
  std::ofstream LogFile;
  std::string filepath;
  if(logArgs[3]=="Log")
     filepath= path + filename_a;
  else
     filepath= path + filename_b;
  LogFile.open(filepath.c_str(), std::ios::app);
     // UNIX Time
  std::time_t now = time(0);
  if(logArgs[3]=="Log")
  {
    LogFile << localtime(&now)->tm_hour << " \"" << logArgs[1] << "\" \"" << logArgs[2]<< "\"" << std::endl;
    std::cout <<localtime(&now)->tm_hour << " \"" << logArgs[1] << "\" \"" << logArgs[2]<< "\"" << std::endl;
    std::cout <<"Task Logged";
  }
  if(logArgs[3]=="Todo")
  {
    LogFile << localtime(&now) << std::endl;
    LogFile << logArgs[2] << std::endl; 
    std::cout<<"Task entered";
  }
  LogFile.close();
}

void logger() { logWriter(); }

void getStats() { std::cout << "Stats feature coming soon " << std::endl; }

void printHelper() {
  std::cout << "Accepted format: \n$ jikan <heading> <details> <Log/Todo>\n$ jikan stats\n$ jikan path\n$ jikan file "<< std::endl;
}
void argHandler() {
  std::string command = logArgs[1];
  if (command == "stats") {
    getStats();
  } else if (command == "file" ) {
    std::cout << "For log" << path+filename_a << std::endl;
    std::cout << "For TO-DO list"<<path+filename_b<<std::endl;
  }else if (command == "path" ) {
    std::cout << path << std::endl;
  } else if (argNum == 4) 
  { // Default 
    logger();
  } else {
    std::cout << command << std::endl;
    printHelper();
  }
}

bool argVectorize(int argc, char *argv[]) {
  argNum = argc;
  if (argNum <4) {
    printHelper();
    return false;
  }
  for (int i = 0; i < argc; i++) {
    logArgs.push_back(std::string(argv[i]));
  }
  return true;
}
int main(int argc, char *argv[]) {
  if (!argVectorize(argc, argv)) {
    return 0;
  }
  argHandler();
  return 0;
}