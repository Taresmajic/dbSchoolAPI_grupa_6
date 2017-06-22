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
  osoba(const std::string id){id_=id;}
  osoba(const std::string id,const std::string fn,const std::string ln,const std::string bd,const std::string em,const std::string gd,const std::string jmb):id_(id),firstName_(fn),lastName_(ln), birthdate_(bd),email_(em),gender_(gd),jmbg_(jmb){}
  
  void setId(const std::string id){id_=id;}
  void setfirstName(const std::string fn){firstName_=fn;}
  void setlastName(const std::string ln){lastName_=ln;}
  void setbirthdate(const std::string bd){birthdate_=bd;}
  void setemail(const std::string em){email_=em;}
  void setgender(const std::string gd){gender_=gd;}
  void setjmbg(const std::string jmb){jmbg_=jmb;}
  
  std::string getId()const{return id_;}
  std::string getfirstName()const{return firstName_;}
  std::string getlastName()const{return lastName_;}
  std::string getbirthdate()const{return birthdate_;}
  std::string getemail()const{return email_;}
  std::string getgender()const{return gender_;}
  std::string getjmbg()const{return jmbg_;}
  
  bool operator<(const osoba& drugi){
    return id_<drugi.id_;
  }
  bool operator>(const osoba& drugi){
    return id_>drugi.id_;
  }
  bool operator==(const osoba& drugi){
    return id_==drugi.id_;
  }
};


#endif
