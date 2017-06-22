#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_
#include<string>

class department{
private:
  std::string id_;
  std::string name_;
public:
  department(){}
  department(const std::string id,const std::string name):id_(id),name_(name){}
  
  void setid(const std::string id){id_=id;}
  void setname(const std::string name){name_=name;}
  
  std::string getid()const{return id_;}
  std::string getname()const{return name_;}
  
  bool operator<(const department& drugi)const{
    return id_<drugi.id_;
  }
  bool operator>(const department& drugi)const{
    return id_>drugi.id_;
  }
  bool operator==(const department& drugi)const{
    return id_==drugi.id_;
  }

};



#endif
