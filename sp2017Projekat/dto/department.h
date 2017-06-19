#ifndef DEPARTMENTS_H_
#define DEPARTMENTS_H_
#include<string>

class departments{
private:
  std::string id_;
  std::string name_;
public:
  departments(const std::string id,const std::string name):id_(id),name_(name){}


};



#endif
