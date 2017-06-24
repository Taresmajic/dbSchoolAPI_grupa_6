#ifndef STUDENT_H_
#define STUDENT_H_
#include "osoba.h"

class student : public osoba{
private:
  std::string departmentId_;
public:
  student(){}
  student(const std::string& id):osoba(id){}
  student(const std::string id,const std::string fn,const std::string ln,const std::string bd,const std::string em,const std::string gd,const std::string jmb,std::string did):osoba(id,fn,ln,bd,em,gd,jmb),departmentId_(did){}

void setDepartmentId(const std::string id){departmentId_=id;}

std::string getDepartmentId()const{return departmentId_;}



};
std::ostream& operator << (std::ostream& out,const student& t){
  out << t.getId() <<", " << t.getFirstName()<<", "<< t.getLastName()<<", " << t.getBirthdate()<<", " << t.getEmail()<<", " << t.getGender()<<", " << t.getJmbg()<<", " << t.getDepartmentId() << std::endl;
  return out;
}

#endif
