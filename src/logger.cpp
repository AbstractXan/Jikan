#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int argNum;
std::vector<std::string> argsList;

std::string path = "/home/abstractxan/Logs/";
std::string filenameLogs = "logs.txt";
std::string filenameTodo = "todo.txt";

void todoWriter(std::string item){
  std::ofstream todoFile;
  std::string filepath = path + filenameTodo;
  todoFile.open(filepath.c_str(), std::ios::app);
  todoFile << item << std::endl; 
  std::cout<< "Task '" << item  << "' added" << std::endl;
  todoFile.close();
}

void logWriter(std::string head, std::string desc) {
  std::ofstream LogFile;
  std::string filepath;
  
  filepath= path + filenameLogs;
  LogFile.open(filepath.c_str(), std::ios::app);
  
  // UNIX Time
  std::time_t now = time(0);
  LogFile << now << " \"" << head << "\" \"" << desc<< "\"" << std::endl;
  std::cout << now << " \"" << head << "\" \"" << desc << "\"" << std::endl;
  std::cout <<"Task Logged" << std::endl;

  LogFile.close();
}

void todoRemove(std::string item){
  std::fstream todoFile;
  std::fstream temp;
  std::string filepath = path + filenameTodo;
  std::string line;
  temp.open("temp.txt",std::ios::out);
  todoFile.open(filepath.c_str());
  while(todoFile.good()){
  	getline(todoFile,line);
  	if(line!=item && line!=""){
  		temp<<line<<std::endl;
  	}
  }
  todoFile.close();
  temp.close();
  remove(filepath.c_str());
  rename("temp.txt",filepath.c_str());
}

void todoDone(std::string item){
  todoRemove(item);
  std::cout << "Enter '"<< item <<"' description" << std::endl << "> ";
  std::string desc;
  std::getline(std::cin >> std::ws, desc);
  std::cout << std::endl;
  logWriter(item,desc);
  std::cout << std::endl;
}

void logger() { 
  if(argNum == 3 && argsList[1] == "add"){
    todoWriter(argsList[2]); 
  }else if(argNum==3 && argsList[1]=="done"){
  	todoDone(argsList[2]);
  }else if(argNum==3 && argsList[1]=="remove"){
  	todoRemove(argsList[2]);
  }
}


void printHelper() {
  std::cout << std::string("usage: jikan <command> [<args>]\n")
    + "These are common Jikan commands:\n"
    +"\ntodo list\n"
        + "   " + "add <item> \t\tAdds item\n"
        + "   " + "done <item> \t\tLogs item\n"
        + "   " + "remove <item> \tRemoves an item\n"
    +"\nprint\n"
        + "   " + "log \t\t\tPrint log\n"
        + "   " + "todo \t\tPrint todo\n"
    +"\nprint paths\n"
        + "   " + "path \t\tShow repository path\n"
    +"\nstats\n"
        + "   " + "stats \t\tShow statistics\n"
  << std::endl;
}

void printLog(){
  std::fstream logFile;
  std::string filepath = path + filenameLogs;
  std::string line;
  logFile.open(filepath.c_str());
  while(logFile.good()){
  	getline(logFile,line);
  	std::cout << line << std::endl;
  }
  logFile.close();
}

void printTodo(){
std::fstream todoFile;
  std::string filepath = path + filenameTodo;
  std::string line;
  todoFile.open(filepath.c_str());
  while(todoFile.good()){
  	getline(todoFile,line);
  	std::cout << line << std::endl;
  }
  todoFile.close();
}
