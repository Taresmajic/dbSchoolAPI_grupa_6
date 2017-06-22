#ifndef STUDENTSSUBJECTSTEACHERS_H_
#define STUDENTSSUBJECTSTEACHERS_H_
#include <string>
#include <iostream>
class studentsSubjectsTeachers{
private:
  std::string studentId_,subjectId_,teacherId_,evaluation_,date_;
public:
  studentsSubjectsTeachers(){};
  studentsSubjectsTeachers(const std::string &stud, std::string &sub, std::string &teacher, std::string &eval,
      std::string &date):studentId_(stud),subjectId_(sub),teacherId_(teacher),evaluation_(eval),date_(date){};
  ~studentsSubjectsTeachers(){}  
  std::string getStudId() const{return studentId_;}  
  std::string getSubId() const{return subjectId_;}  
  std::string getTeacherId() const{return teacherId_;}  
  std::string getEval() const{return evaluation_;}  
  std::string getDate() const{return date_;}
  void setStudId(const std::string &dummy){studentId_=dummy;}
  void setSubId(const std::string &dummy){subjectId_=dummy;}
  void setTeacherId(const std::string &dummy){teacherId_=dummy;}
  void setEval(const std::string &dummy){evaluation_=dummy;}
  void setDate(const std::string &dummy){date_=dummy;}
  bool operator < (const studentsSubjectsTeachers &dummy)const{return studentId_<dummy.studentId_;}
  bool operator > (const studentsSubjectsTeachers &dummy)const{return studentId_>dummy.studentId_;}
  bool operator == (const studentsSubjectsTeachers &dummy)const{return studentId_==dummy.studentId_;}
};

std::ostream& operator << (std::ostream& out,const studentsSubjectsTeachers& sst){
  out << sst.getStudId() << sst.getSubId() << sst.getTeacherId() << sst.getEval() << sst.getDate() << std::endl;
  return out;}


#endif
