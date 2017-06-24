#ifndef OSOBA_H_
#define OSOBA_H_
#include<string>
#include<iostream>
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
  osoba(const std::string id){id_=id;}
  osoba(const std::string id,const std::string fn,const std::string ln,const std::string bd,const std::string em,const std::string gd,const std::string jmb):id_(id),firstName_(fn),lastName_(ln), birthdate_(bd),email_(em),gender_(gd),jmbg_(jmb){}
  
  void setId(const std::string id){id_=id;}
  void setFirstName(const std::string fn){firstName_=fn;}
  void setLastName(const std::string ln){lastName_=ln;}
  void setBirthdate(const std::string bd){birthdate_=bd;}
  void setEmail(const std::string em){email_=em;}
  void setGender(const std::string gd){gender_=gd;}
  void setJmbg(const std::string jmb){jmbg_=jmb;}
  
  std::string getId()const{return id_;}
  std::string getFirstName()const{return firstName_;}
  std::string getLastName()const{return lastName_;}
  std::string getBirthdate()const{return birthdate_;}
  std::string getEmail()const{return email_;}
  std::string getGender()const{return gender_;}
  std::string getJmbg()const{return jmbg_;}
  
  bool operator < (const osoba& drugi)const{
    return id_ < drugi.id_;
  }
  bool operator > (const osoba& drugi)const{
    return id_ > drugi.id_;
  }
  bool operator == (const osoba& drugi)const{
    return id_ == drugi.id_;
  }
};


#endif
