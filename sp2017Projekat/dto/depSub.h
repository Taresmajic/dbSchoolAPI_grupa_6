#ifndef DEPSUB_H_
#define DEPSUB_H_
#include <string>
#include <iostream>
class depSub{
private:
 std::string departmentId_, subjectId_,studyYear_, studySemester_;
public:

  depSub(){};
  depSub(const std::string &deptId,const std::string  &subId,const std::string &studyYear,const std::string &studySemester):departmentId_(deptId),subjectId_(subId),studyYear_(studyYear),studySemester_(studySemester){};
  ~depSub(){};
  std::string getDeptId() const{return departmentId_;}  
  std::string getSubId() const{return subjectId_;}
  std::string getStudyYear() const{return studyYear_;}
  std::string getSemester() const{return studySemester_;}
  void setDeptId(const std::string &dummy){departmentId_=dummy;}
  void setSubId(const std::string &dummy){subjectId_=dummy;}
  void setStudyYear(const std::string &dummy){studyYear_=dummy;}
  void setSemester(const std::string &dummy){studySemester_=dummy;}
  bool operator < (const depSub &dummy)const{return departmentId_<dummy.departmentId_;}
  bool operator > (const depSub &dummy)const{return departmentId_>dummy.departmentId_;}
  bool operator == (const depSub &dummy)const{return departmentId_==dummy.departmentId_;}
  
};

std::ostream& operator << (std::ostream& out,const depSub& ds){
  out << ds.getDeptId()<<", " << ds.getSubId()<<", " <<  ds.getStudyYear()<<", " << ds.getSemester() <<std::endl;
  return out;}








#endif
