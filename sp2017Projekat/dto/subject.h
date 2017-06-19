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
  void setid(const std::string id){id_=id;}
  void setname(const std::string name){name_=name;}
  void setects(const std::string ects){ects_=ects;}
  void setabb(const std::string ab){abb_=ab;}
  std::string getid()const{return id_;} 
  std::string getname()const{return name_;}
  std::string getects()const{return ects_;}
  std::string getabb()const{return abb_;}
  
};


#endif
