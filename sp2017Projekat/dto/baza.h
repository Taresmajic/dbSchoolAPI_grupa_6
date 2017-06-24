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

  // Metod vraca kontejner studentsubjectteacher-a a uzima student id
  
  List<studentsSubjectsTeachers> getAllSubjects(const std::string& studentID){
   List<studentsSubjectsTeachers> tempList;
    for(int i=0;i<serviceStudentsSubjectsTeachers.size();++i){
      if(serviceStudentsSubjectsTeachers[i].getStudId()==studentID){
        tempList.insert(serviceStudentsSubjectsTeachers[i]);
      }
    }
    return tempList;
  }

  // Metod vraca eval predmeta a uzima studentID i subjectID
  
  std::string getStudentEval(const std::string &studentID, const std::string &subjectID){
    for(int i=0; i<serviceStudentsSubjectsTeachers.size();++i){
      if(serviceStudentsSubjectsTeachers[i].getStudId()==studentID && serviceStudentsSubjectsTeachers[i].getSubId()==subjectID)
        return serviceStudentsSubjectsTeachers[i].getEval();
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
  std::string getSubjectTeacher(const std::string& subjectID)const{
    for(int i=0;i<serviceSubjectTeachers.size();++i){
      if(serviceSubjectTeachers[i].getSubId()==subjectID){
        return getTeacherById(serviceSubjectTeachers[i].getTeacherId()).getFirstName() + 
          getTeacherById(serviceSubjectTeachers[i].getTeacherId()).getLastName(); 
      }
    }
    return std::string{};
  }
  //Metod vraca teacher-a po ID-u
  teacher getTeacherById(const std::string &teacherID)const{
    for(int i=0;i<teacherList.size();++i){
      if(teacherList[i].getId()==teacherID){
        return teacherList[i];
      }
    }
    return teacher{};
  }

  // Metod koji vraca studenta a uzima njegov ID
  
  student getStudentById(const std::string &studentID)const{
    for(int i=0;i<studentList.size();++i){
      if(studentList[i].getId()==studentID){
        return studentList[i];
      }
    }
    return student{};
  }

  // Metod koji vraca subject a uzima njegov ID
  
  subject getSubjectById(const std::string &subjectID)const{
    for(int i=0;i<subjectList.size();++i){
      if(subjectList[i].getId()==subjectID)
        return subjectList[i];
    }
    return subject{};
  }

  // Metod koji vraca subject info a uzima subject ID
  
  depSub getSubjectInfo(const std::string & subjectID)const{
    for(int i=0;i<serviceDepSub.size();++i){
      if(serviceDepSub[i].getSubId()==subjectID)
        return serviceDepSub[i];
    }
    return depSub{};
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


// Ispis svih studenata sa nekog predmeta.   //***getStudentEval  
void svisapredmeta(const Vektor<student>& vec, const std::string& subId){
  for(auto i=0;i<vec.size();++i){
    std::cout << "Id: " <<vec[i].getId() << "\t" << "Last Name: "  << vec[i].getLastName() << "First Name: "  << vec[i].getFirstName() <<"\t"<< "Eval: "  << getStudentEval(vec[i].getId(),subId) << "\t" << "Department: "  << getStudentDepartment(vec[i].getId()) << "Teacher: "  << getSubjectTeacher(subId) << std::endl ;
  }
}

// Ispis svih predmeta.
void svipredmeti(const Vektor<teacher> & vec){
  for(auto i=0; i<vec.size() ; ++i){
    std::cout << "Id: " << vec[i].getId()<< "\t" << "Last Name: " << vec[i].getLastName() << "\t" << "First Name: " << vec[i].getFirstName() << "\t" << "Department:" << getDepartmentById(vec[i].getDepartmentId()) << std::endl;
  }
}
  //kraj ispisa
  
  //Insert metode

bool existJMBG(const std::string &jmbg)const{
  for(int i=0;i<studentList.size();++i){
    if(studentList[i].getJmbg()==jmbg)
      return true;
  }
  return false;
}
template <typename T>
std::string idSeter(const List<T> &tempList){
 int i;
  for(i=1;i<=tempList.size();++i){
    if(tempList[i-1].getId()!=std::to_string(i)){
      return std::to_string(i);
    }
  }
  return std::to_string(i);
}

bool insertSubject(subject dummySub){
  for(int i=0;i<subjectList.size();++i){
    if(dummySub.getName()==subjectList[i].getName())
      return false;
  }
  dummySub.setId(idSeter(subjectList)); //setujemo ID
  subjectList.insert(dummySub);
  return true;
}

bool insertStudent(student dummyStud){
  if(!existJMBG(dummyStud.getJmbg())){
    dummyStud.setId(idSeter(studentList));//setujemo ID
    studentList.insert(dummyStud);
    return true;
  }
  else{
    return false;
  }
  
}

bool insertTeacher(teacher dummyTeacher){
  if(!existJMBG(dummyTeacher.getJmbg())){
    dummyTeacher.setId(idSeter(teacherList));//setujemo ID
    teacherList.insert(dummyTeacher);
    return true;
  }
  else{
    return false;
  }
  
}






  //Kraj insert metoda
};




#endif
