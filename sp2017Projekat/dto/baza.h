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
  //Metod koji vraca smijer a uzima id predmeta
  department getSubjectDepartment(const std::string& subjectID){
    for(int i=0;i<serviceDepSub.size();++i){
      if(serviceDepSub[i].getSubId()==subjectID){
        return getDepartmentById(serviceDepSub[i].getDeptId());
      }
    }
    return department{};
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

// Ispis svih profesora.
void sviprofesori(const Vektor<teacher> & vec){
  for(auto i=0; i<vec.size() ; ++i){
    std::cout << "Id: " << vec[i].getId()<< "\t" << "Last Name: " << vec[i].getLastName() << "\t" << "First Name: " << vec[i].getFirstName() << "\t" << "Department:" << getDepartmentById(vec[i].getDepartmentId()) << std::endl;
  }
}

// ispis svih predmeta.
void svipredmeti(const Vektor<subject>& vec){
  for(auto i=0;i<vec.size();++i){
    std::cout << "Id: " << vec[i].getId() << "\t"<<"Name: " << vec[i].getName() << "\t"<<"Ects: " <<vec[i].getEcts() << "\t" << "Abbreviation: " << vec[i].getAbb() <<"\t"<<"Department: "<<getSubjectDepartment(vec[i].getId()).getName() << std::endl;
  }
}
  //kraj ispisa

  //ovde funkcije koje vracaju vektor za ispis prethodni

  //funkcija vraca vektor za ispisivanje svih studenata.
Vektor<student> Makesvistudenti(){
  Vektor<student> st(studentList.size());
    st=studentList;
    st.sort(Poprezimenus);
    return st;
}

  //funkcija vraca vektor studenata sa smjera.
Vektor<student> MakeStudentisasmjera(const std::string kojismjer){
  Vektor<student> st(studentList.size());
    for(int i=0;i<studentList.size();++i)
      { if(studentList[i].getDepartmentId()==kojismjer)
        st.push(studentList[i]);}
      st.sort(Poprezimenus);
    return st;
  }

  //Funkcija vraca vektor svih studenata sa predmeta.
Vektor<student> Makesvisapredmeta(const std::string kojipredmet){
  Vektor<student> st(studentList.size());
   for(int i=0;i<studentList.size();++i){  
     List<studentsSubjectsTeachers> lista=getAllSubjects(st[i].getId());
     for(int j=0;j<lista.size();++j)
      {if(lista[j].getSubId()==kojipredmet)
       st.push(studentList[i]);}
    }  
  st.sort(Poprezimenus);
  return st;
 }

  //Funkcija vraca vektor svih teachera.
Vektor<teacher> Makesviprofesori(){
  Vektor<teacher> tch(teacherList.size());
  tch=teacherList;
  tch.sort(Poprezimenut);
  return tch;
  }

  //Funkcija vraca vektor svih predmeta.
Vektor<subject> Makesvipredmeti(){
  Vektor<subject> su(subjectList.size());
  su=subjectList;
  su.sort(Poid);
  return su;
}
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







bool insertDepartment(department tempDep){
  for(int i=0;i<departmentList.size();++i){
    if(departmentList[i].getName()==tempDep.getName())
      return false;
  }
  tempDep.setId(idSeter(departmentList));
  departmentList.insert(tempDep);
  return true;
}
// insertujemo student subject teacher
bool insertSST(studentsSubjectsTeachers dummySST){
  for(int i=0;i<serviceStudentsSubjectsTeachers.size();++i){
    if(serviceStudentsSubjectsTeachers[i].getStudId()==dummySST.getStudId() &&
        serviceStudentsSubjectsTeachers[i].getSubId()==dummySST.getSubId()){
      return false;
    }
  }
    serviceStudentsSubjectsTeachers.insert(dummySST);
    return true;
  
}

bool insertSubjectTeacher(subjectTeachers dummyST){
  for(int i=0;i<serviceSubjectTeachers.size();++i){
    if(serviceSubjectTeachers[i].getSubId()==dummyST.getSubId()){
      return false;
    }
  }
  serviceSubjectTeachers.insert(dummyST);
  return true;
}

bool insertDepartmentsSubjects(depSub dummyDS){
  for(int i=0;i<serviceDepSub.size();++i){
    if(serviceDepSub[i].getSubId()==dummyDS.getSubId()){
      return false;
    }
  }
  serviceDepSub.insert(dummyDS);
  return true;
}


  //Kraj insert metoda
  
  //Update metodi
 //Unutar maina vrsi se provjera sta mijenjamo kod teachera i studenta
 
void setTeacher(const teacher & tempTeacher, int index){ //metod uzima teachera i indeks na koji ga smjesta
  teacherList[index]=tempTeacher;
} 
 void setStudent(const student & tempStud, int index){ //metod uzima studenta  i indeks na koji ga smjesta
  studentList[index]=tempStud;
} 
 
 void setSubject(const subject & tempSub, int index){ //metod uzima subject i indeks na koji ga smjesta
  subjectList[index]=tempSub;
} 
  void setSST(const studentsSubjectsTeachers & tempSST, int index){ //metod uzima studentSubjectTeacher i indeks na koji ga smjesta
  serviceStudentsSubjectsTeachers[index]=tempSST;
} 
  void setSubTeacher(const subjectTeachers & tempST, int index){ //metod uzima subjecta i teachera i indeks na koji ga smjesta
  serviceSubjectTeachers[index]=tempST;
} 
 void setDepSub(const depSub & tempDS, int index){ //metod uzima depSUb i indeks na koji ga smjesta
  serviceDepSub[index]=tempDS;
} 
 
 
  //Kraj update metoda
};




#endif
