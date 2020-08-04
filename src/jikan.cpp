#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "logger.cpp"
#include "exporter.cpp"
#include "analyzer.cpp"

void argHandler() {
  if (argNum==2){
      std::string command = argsList[1];
      if (command == "stats") {
        getStats();
      } else if (command == "log" ) {
        printLog();
      }  else if (command == "todo" ) {
        printTodo();
      } else if (command == "path" ) {
        std::cout << path << std::endl;
      } else if (command =="export"){
      	getExport();
      }
  } else if (argNum==3) { 
    logger();
  } else {
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