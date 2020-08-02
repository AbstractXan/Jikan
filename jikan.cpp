#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
std::string filenameLogs = "logs.txt";
std::string filenameTodo = "todo.txt";
std::string path = "/home/abstractxan/Logs/";
int argNum;
std::vector<std::string> argsList;

void todoWriter(){
  std::ofstream todoFile;
  std::string filepath = path + filenameTodo;
  todoFile.open(filepath.c_str(), std::ios::app);
  todoFile << argsList[2] << std::endl; 
  std::cout<< "Task '" << argsList[2] << "' added" << std::endl;
  todoFile.close();
}

void logWriter() {
  std::ofstream LogFile;
  std::string filepath;
  
  filepath= path + filenameLogs;
  LogFile.open(filepath.c_str(), std::ios::app);
  
  // UNIX Time
  std::time_t now = time(0);
  LogFile << now << " \"" << argsList[1] << "\" \"" << argsList[2]<< "\"" << std::endl;
  std::cout << now << " \"" << argsList[1] << "\" \"" << argsList[2]<< "\"" << std::endl;
  std::cout <<"Task Logged" << std::endl;

  LogFile.close();
}

void todoRemove(){
  std::fstream todoFile;
  std::fstream temp;
  std::string filepath = path + filenameTodo;
  std::string line;
  temp.open("temp.txt",std::ios::out);
  todoFile.open(filepath.c_str());
  while(todoFile.good()){
  	getline(todoFile,line);
  	if(line!=argsList[2] && line!=""){
  		temp<<line<<std::endl;
  	}
  }
  todoFile.close();
  temp.close();
  remove(filepath.c_str());
  rename("temp.txt",filepath.c_str());
  std::cout<<"Task removed from ToDo" << std::endl;
}

void logger() { 
  if(argNum == 3 && argsList[1] == "add"){
    todoWriter(); 
  }else if(argNum==3 && argsList[1]=="remove"){
  	todoRemove();
  } else if (argNum == 3){
    logWriter();
  }
}

void getStats() { std::cout << "Stats feature coming soon " << std::endl; }

void printHelper() {
  std::cout << std::string("usage: jikan <command> [<args>]\n")
    + "These are common Jikan commands:\n"
    +"\nlog task\n"
        + "   " + "<head> <desc> \tAdds a task of type 'work'\n" 
    +"\nprint paths\n"
        + "   " + "path \t\tShow repository path\n"
        + "   " + "file \t\tShow logfile path\n"
        + "   " + "todo \t\tShow todo path\n"
    +"\ntodo list\n"
        + "   " + "add <item> \t\tAdds a todo item\n"
        + "   " + "remove <item> \tRemoves a todo item\n"
    +"\nstats\n"
        + "   " + "stats \t\tShow statistics\n"
  << std::endl;
}


void argHandler() {
  std::string command = argsList[1];
  if (command == "stats") {
    getStats();
  } else if (command == "file" ) {
    std::cout << path + filenameLogs << std::endl;
  } else if (command == "path" ) {
    std::cout << path << std::endl;
  } else if (command == "todo" ) {
    std::cout << path + filenameTodo << std::endl;
  } else if (3 <= argNum && argNum <= 4) { 
    logger();
  } else {
    std::cout << command << std::endl;
    printHelper();
  }
}

bool argVectorize(int argc, char *argv[]) {
  argNum = argc;
  if (argNum < 2) {
    printHelper();
    return false;
  }
  for (int i = 0; i < argc; i++) {
    argsList.push_back(std::string(argv[i]));
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