// multiple handlers have the chance to process a request, but the request is passed through the chain until one handler processes it. 
#include<bits/stdc++.h>
using namespace std;

enum logLevel{
  INFO = 1,
  DEBUG = 2,
  ERROR = 3
};

class Logger{
protected:
  int level;
  Logger* nextLogger;
public:
  Logger(): nextLogger(nullptr) {}
  void setNextLogger(Logger* nextLogger){
    this->nextLogger = nextLogger;
  }
};