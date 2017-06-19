#ifndef SUBJECT_H_
#define SUBJECT_H_
#include<string>

class subject{
private:
  std::string id_;
  std::string name_;
  std::string ects_;
  std::string abb_;
public:
  subject(){}
  subject(const std::string id,const std::string n,const std::string ects,const std::string ab):id_(id),name_(n),ects_(ects),abb_(ab){}
 
  
};


#endif
