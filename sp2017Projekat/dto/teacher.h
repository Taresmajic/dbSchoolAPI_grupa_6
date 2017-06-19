#ifndef TEACHER_H_
#define TEACHER_H_
#include "osoba.h"
class teacher : public osoba{
private:
  std::string departmentId_;
public:
  teacher(const std::string id,const std::string fn,const std::string ln,const std::string bd,const std::string em,const std::string gd,const std::string jmb,std::string did){
    osoba(id,fn,ln,bd,em,gd,jmb);
    departmentId_=did;
  }

};

#endif
