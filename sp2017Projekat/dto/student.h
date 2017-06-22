#ifndef STUDENT_H_
#define STUDENT_H_
#include "osoba.h"

class student : public osoba{
private:
  std::string departmentId_;
public:
  student(){}
  student(const std::string id,const std::string fn,const std::string ln,const std::string bd,const std::string em,const std::string gd,const std::string jmb,std::string did):osoba(id,fn,ln,bd,em,gd,jmb),departmentId_(did){}

void setdepartmentId(const std::string id){departmentId_=id;}

std::string getdepartmentId()const{return departmentId_;}

};


#endif
