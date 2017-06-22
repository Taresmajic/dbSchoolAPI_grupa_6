#ifndef SUBJECT_H_
#define SUBJECT_H_
#include<string>
#include<iostream>

class subject{
private:
  std::string id_;
  std::string name_;
  std::string ects_;
  std::string abb_;
public:
  subject(){}
  subject(const std::string id,const std::string n,const std::string ects,const std::string ab):id_(id),name_(n),ects_(ects),abb_(ab){}
  
  void setId(const std::string id){id_=id;}
  void setName(const std::string name){name_=name;}
  void setEcts(const std::string ects){ects_=ects;}
  void setAbb(const std::string ab){abb_=ab;}
  
  std::string getId()const{return id_;} 
  std::string getName()const{return name_;}
  std::string getEcts()const{return ects_;}
  std::string getAbb()const{return abb_;}
  
  bool operator < (const subject& drugi)const{
    return id_ < drugi.id_;
  }
  bool operator > (const subject& drugi)const{
    return id_ > drugi.id_;
  }
  bool operator == (const subject& drugi)const{
    return id_ == drugi.id_;
  }

};
std::ostream& operator << (std::ostream& out,const subject& su){
  out << su.getId() << su.getName() << su.getEcts() << su.getAbb()<< std::endl;
  return out;}

#endif
