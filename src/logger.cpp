#include <fstream>
#include <iostream>
#include <vector>
#include <ctime>
#include <string>

int argNum;

std::vector<std::string> argsList;

std::string path = "/home/abstractxan/Logs/";
std::string filenameLogs = "logs.txt";
std::string filenameTodo = "todo.txt";
std::string filenameTemp = "temp.txt";


// UNIX Time
std::time_t now = time(0);

void todoWriter(std::string item){
  std::ofstream todoFile;
  std::string filepath = path + filenameTodo;
  todoFile.open(filepath.c_str(), std::ios::app);
  todoFile << item << std::endl; 
  std::cout<< "Task '" << item  << "' added" << std::endl;
  todoFile.close();
}

void logWriter(std::string data_A, std::string data_B,std::string data_C,std::string data_D,std::string data_E,std::string data_F) 
{
  std::ofstream LogFile;
  std::string filepath;
  
  filepath= path + filenameLogs;
  LogFile.open(filepath.c_str(), std::ios::app);
  
  
  LogFile << "\"" << data_A << "\" \"" <<data_B<< "\" \""<<data_C <<"\" \"" <<data_D<< "\" \""<<data_E<<"\" \"" <<data_F<< "\"" <<std::endl;

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

void endTask(std::string item){

  //Get Temp data
  //std::vector<std::string>data;
  std::string data;
  std::string line;
  std::fstream tempFile;
  std::string filepath = path + filenameTemp;
  std::cout << filepath << std::endl;
  tempFile.open(filepath.c_str());

  if(tempFile.good()){
    getline(tempFile,line);
  }

  std::string delimiter="--";
  std::string start=line.substr(0,line.find(delimiter));
  std::cout << start << std::endl;


  char cur[80];
  time(&now);
  struct tm * timeinfo=localtime(&now);

  strftime(cur,sizeof(cur),"%d-%m-%Y %H:%M:%S",timeinfo);
  std::string end(cur);
  // std::string delimiter="--";
  // std::string start=data.substr(0,data.find(delimiter));
  
  std::cout << start << std::endl;
  
  //Write start_time+end_time
  //logWriter(start,end);

  int yy, month, dd, hh, mm, ss;
  time_t tStart;
  struct tm tm;
  const char *zs=start.c_str();
  sscanf(zs,"%d/%d/%d %d:%d:%d",&yy, &month, &dd, &hh, &mm, &start);
  tm.tm_year = yy - 1900;
  tm.tm_mon = month - 1;
  tm.tm_mday = dd;
  tm.tm_hour = hh;
  tm.tm_min = mm;
  tm.tm_sec = ss;
  tm.tm_isdst = -1;
  tStart=mktime(&tm);

  time_t duration=now-tStart;
  struct tm * tinfo=localtime(&now);
  tinfo=localtime(&duration);
  strftime(cur,sizeof(cur),"%d-%m-%Y %H:%M:%S",tinfo);
  std::string interval(cur);
  
  std::cout<<"Time taken:"<<std::endl;
  std::cout<<interval<<std::endl;


  //Writing duration+task_name
  //logWriter(start,end,interval,item);

  //Remove temp file
  remove(filepath.c_str());

  //Getting category
  std::cout<<"Enter  "<<item<<"Category"<<std::endl<<"> ";
  std::string cat;
  std::getline(std::cin>>std::ws,cat);
  std::cout<<std::endl;

  //Get descr.
  std::cout << "Enter '"<< item <<"' description" << std::endl << "> ";
  std::string desc;
  std::getline(std::cin >> std::ws, desc);
  std::cout << std::endl;

  //Writing all data points to file
  logWriter(start,end,interval,item,cat,desc);
  std::cout <<"Task Logged" << std::endl;
  std::cout << std::endl;

  //Remove from To-Do
  todoRemove(item);
}

void startTask(std::string task){

  std::ofstream tempFile;

  std::string filepath = path + filenameTemp;
  tempFile.open(filepath.c_str(), std::ios::app);
  tempFile<<now<<"--"<<task<<std::endl;
  tempFile.close();
  std::cout<<task<<"--started"<<std::endl;
}

void currTask(){
  std::string line;
  std::fstream tempFile;
  std::string filepath = path + filenameTemp;
  tempFile.open(filepath.c_str());

  while(tempFile.good()){
    getline(tempFile,line);
    std::cout<<line;
  }
}

void logger() { 
  if(argNum == 3 && argsList[1] == "add"){
    todoWriter(argsList[2]); 
  }else if(argNum==3 && argsList[1]=="start"){
  	startTask(argsList[2]);
  }else if(argNum==3 && argsList[1]=="end"){
  	endTask(argsList[2]);
  }else if(argNum==3 && argsList[1]=="break"){
    endTask(argsList[2]);
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
