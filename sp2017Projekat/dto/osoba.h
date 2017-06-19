#ifndef OSOBA_H_
#define OSOBA_H_
#include<string>

class osoba{
private:
  std::string id_;
  std::string firstName_;
  std::string lastName_;
  std::string birthdate_;
  std::string email_;
  std::string gender_;
  std::string jmbg_;
public:
  osoba(){}
  osoba(const std::string id,const std::string fn,const std::string ln,const std::string bd,const std::string em,const std::string gd,const std::string jmb):id_(id),firstName_(fn),lastName_(ln), birthdate_(bd),email_(em),gender_(gd),jmbg_(jmb){}
  void setId(std::string id){id_=id;}
  std::string getId()const{return id_;}
};


#endif
