#ifndef DEPARTMENTS_H_
#define DEPARTMENTS_H_
#include<string>

class departments{
private:
  std::string id_;
  std::string name_;
public:
  departments(){}
  departments(const std::string id,const std::string name):id_(id),name_(name){}
  void setid(const std::string id){id_=id;}
  void setname(const std::string name){name_=name;}
  std::string getid()const{return id_;}
  std::string getname()const{return name_;}
  bool operator<(const departments& drugi){
    return id_<drugi.id_;
  }
  bool operator>(const departments& drugi){
    return id_>drugi.id_;
  }
  bool operator==(const departments& drugi){
    return id_==drugi.id_;
  }

};



#endif
