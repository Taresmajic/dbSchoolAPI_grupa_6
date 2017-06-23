#ifndef SCHOOL_H_
#define SCHOOL_H_
#include"List.h"
#include"student.h"
#include"teacher.h"
#include"subject.h"
#include"subjectTeachers.h"
#include"depSub.h"
#include"studentsSubjectsTeachers.h"
#include"department.h"
#include"Vektor.h"

class Base{
private:
//Liste baznih fajlova
List<student> studentList;                                      
List<teacher> teacherList;
List<subject> subjectList;
List<department> departmentList;
//Liste link fajlova
List<subjectTeachers> serviceSubjectTeachers;
List<depSub> serviceDepSub;
List<studentsSubjectsTeachers> serviceStudentsSubjectsTeachers;
public:
  Base(){}
  ~Base(){}
  //Konstruktor za ubacivanje txt u liste
  
  //Metod vraca department preko studentovog id-a
  std::string getStudentDepartment(const std::string& studentID)const{
    for(int i=0;i<studentList.size();++i){
      if(studentList[i].getId()==studentID){
        return getDepartmentById(studentList[i].getDepartmentId());
      }
    }
    return std::string{};
  }
  //Metod koji vraca ime departmen-a preko id-a
  std::string getDepartmentById(const std::string& depID)const{
    for(int i=0;i<departmentList.size();++i){
      if(departmentList[i].getId()==depID){
        return departmentList[i].getName();
      }
    }
    return std::string{};
  }
  //Metod vraca ime+prezime teachera koji je na odredjenom predmetu
  std::string getSubjectTeacher(std::string& subjectID)const{
    for(int i=0;i<serviceSubjectTeachers.size();++i){
      if(serviceSubjectTeachers[i].getSubId()==subjectID){
        return getTeacherById(serviceSubjectTeachers[i].getTeacherId()).getFirstName() + 
          getTeacherById(serviceSubjectTeachers[i].getTeacherId()).getLastName(); 
      }
    }
    return std::string{};
  }
  //Metod vraca teacher-a po ID-u
  teacher getTeacherById(std::string teacherID)const{
    for(int i=0;i<teacherList.size();++i){
      if(teacherList[i].getId()==teacherID){
        return teacherList[i];
      }
    }
    return teacher{};
  }

  //  Ispisi keno su poslije ovog komentara... kapiras
  
 // Ispis za sve studente, ispisuje id, prezime, ime, department.
void svistudenti(const Vektor<student>& vec){
  for(auto i=0;i<vec.size();++i){
    std:: cout<< "Id: "  <<vec[i].getId() << "\t" << "Last Name: "  << vec[i].getLastName() << "\t" << "First Name: "  << vec[i].getFirstName() <<"\t" << "Department: "  << getStudentDepartment(vec[i].getId()) << std::endl;
  }
}


// Ispis za sve studente sa nekog smjera.
void studentisasmjera(const Vektor<student>& vec){
  for(auto i=0;i<vec.size();++i){
    std::cout<<"Id: "  << vec[i].getId() << "\t" <<"Last Name: "  << vec[i].getLastName() << "\t" << "First Name: "  << vec[i].getFirstName() << std::endl ;
  }
}


// Ispis svih studenata sa nekog predmeta.   //***getStudentEval ***subID 
void svisapredmeta(const Vektor<student>& vec, const std::string& subId){
  for(auto i=0;i<vec.size();++i){
    std::cout << "Id: " <<vec[i].getId() << "\t" << "Last Name: "  << vec[i].getLastName() << "First Name: "  << vec[i].getFirstName() <<"\t"<< "Eval: "  << getStudentEval(vec[i].getId()) << "\t" << "Department: "  << getStudentDepartment(vec[i].getId()) << "Teacher: "  << getSubjectTeacher(subId) << std::endl ;
  }
}

// Ispis svih predmeta.
void svipredmeti(const Vektor<teacher> & vec){
  for(auto i=0; i<vec.size() ; ++i){
    std::cout << "Id: " << vec[i].getId()<< "\t" << "Last Name: " << vec[i].getLastName() << "\t" << "First Name: " << vec[i].getFirstName() << "\t" << "Department:" << getDepartmentById(vec[i].getDepartmentId()) << std::endl;
  }
}
  //kraj ispisa
  

};




#endif
