#ifndef SUBJECTTEACHERS_H_
#define SUBJECTTEACHERS_H_
#include <string>
#include <iostream>

class subjectTeachers{

private:
  std::string subjectId_, teacherId_; 
public:
  subjectTeachers(){};
  subjectTeachers(const std::string &subId,std::string &teacherId):subjectId_(subId),teacherId_(teacherId){}
  ~subjectTeachers(){};
  std::string getSubId()const{return subjectId_;}
  std::string getTeacherId()const{return teacherId_;}
  void setSubId(const std::string &dummy){subjectId_=dummy;}
  void setTeacherId(const std::string &dummy){teacherId_=dummy;  }
  bool operator < (const subjectTeachers &dummy )const{return subjectId_<dummy.subjectId_;}
  bool operator > (const subjectTeachers &dummy )const{return subjectId_>dummy.subjectId_;}
  bool operator == (const subjectTeachers &dummy )const{return subjectId_==dummy.subjectId_;}
   
};

std::ostream& operator << (std::ostream& out,const subjectTeachers& st){
  out << st.getSubId() << st.getTeacherId() << std::endl;
  return out;}


#endif
