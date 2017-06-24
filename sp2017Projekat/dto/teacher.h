#ifndef TEACHER_H_
#define TEACHER_H_

#include "osoba.h"
class teacher : public osoba{
private:
  std::string departmentId_;
  std::string title_;
public:
  teacher(){}
  teacher(const std::string id,const std::string fn,const std::string ln,const std::string bd,const std::string em,const std::string gd,const std::string jmb,const std::string title,const std::string did)
   :osoba(id,fn,ln,bd,em,gd,jmb),departmentId_(did),title_(title){};

void setDepartmentId(const std::string id){departmentId_=id;}
void setTitle(const std::string title){title_=title;}

std::string getTitle()const{return title_;}
std::string getDepartmentId()const{return departmentId_;}
};
std::ostream& operator << (std::ostream& out,const teacher& t){
  out << t.getId() <<", " << t.getFirstName()<<", "<< t.getLastName()<<", " << t.getBirthdate()<<", " << t.getEmail()<<", " << t.getGender()<<", " << t.getJmbg()<<", " << t.getTitle()<< ", " << t.getDepartmentId() << std::endl;
  return out;
}

#endif
