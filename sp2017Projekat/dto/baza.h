#ifndef BAZA_H_
#define BAZA_H_
#include"List.h"
#include"student.h"
#include"teacher.h"
#include"subject.h"
#include"subjectTeachers.h"
#include"depSub.h"
#include"studentsSubjectsTeachers.h"
#include"department.h"
#include"Vektor.h"
#include"parsiranje.h"

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
void ispis(){
  std::cout  <<  serviceStudentsSubjectsTeachers.size() << serviceDepSub.size() << serviceSubjectTeachers.size();
}
// Konstruktor za ubacivanje txt u liste
Base(){

  // Ucitavanje za students.txt
  std::fstream studfajl("../db/students.txt");
 std::string studi;
 while(getline(studfajl,studi))
   parsiraj(studentList,studi);

 // Ucitavanje za teachers.txt
 std::fstream teachfajl("../db/teachers.txt");
 std::string teachi;
 while(getline(teachfajl,teachi))
   parsiraj(teacherList,teachi);

 // Ucitavanje za departments.txt
 std::fstream depfajl("../db/departments.txt");
 std::string depi;
 while(getline(depfajl,depi))
   parsiraj(departmentList,depi);

 // Ucitavanje za subjects.txt
 std::fstream subfajl("../db/subjects.txt");
 std::string subi;
 while(getline(subfajl,subi))
   parsiraj(subjectList,subi);

 // Ucitavanje za departments-subjects.txt
 std::fstream depsubfajl("../db/departments-subjects.txt");
 std::string depsubi;
 while(getline(depsubfajl,depsubi))
   parsiraj(serviceDepSub,depsubi);

 // Ucitavanje za students-subjects-teachers.txt
 std::fstream sstifajl("../db/students-subjects-teachers.txt");
 std::string sstii;
 while(getline(sstifajl,sstii))
   parsiraj(serviceStudentsSubjectsTeachers,sstii);

 // Ucitavanje za subjects-teachers.txt
 std::fstream subteachfajl("../db/subjects-teachers.txt");
 std::string subti;
 while(getline(subteachfajl,subti))
   parsiraj(serviceSubjectTeachers,subti);
}

  ~Base(){}
// Metod koji upisuhe sve liste u txt fajlove
  void alltxt(){
    stutxt(studentList);
    deptxt(departmentList);
    depsubtxt(serviceDepSub);
    studsubtchtxt(serviceStudentsSubjectsTeachers);
    subtxt(subjectList);
    subtchtxt(serviceSubjectTeachers);
    tchhtxt(teacherList);
  }
  
  //Metod vraca department preko studentovog id-a
  std::string getStudentDepartment(const std::string& studentID)const{
    for(int i=0;i<studentList.size();++i){
      if(studentList[i].getId()==studentID){
        return getDepartmentById(studentList[i].getDepartmentId());
      }
    }
    return std::string{};
  }
  // Metod vraca dep aa prima id teachera
    std::string getTeacherDepartment(const std::string& teacherID)const{
    for(int i=0;i<teacherList.size();++i){
      if(teacherList[i].getId()==teacherID){
        return getDepartmentById(teacherList[i].getDepartmentId());
      }
    }
    return std::string{};
  }
  // metod koji vraca teacher a uzima depid
  List<teacher> getTeacherfromDepartment(const std::string& depId)const{
    List<teacher> jedan;
    for(int i=0;i<teacherList.size();++i){
      if(std::stoi(teacherList[i].getDepartmentId())==std::stoi(depId)){
        jedan.insert(teacherList[i]);
      }
    }
    return jedan;
  }


  //Metod koji vraca smijer a uzima id predmeta
  department getSubjectDepartment(const std::string& subjectID){
    for(int i=0;i<serviceDepSub.size();++i){
      if(std::stoi(serviceDepSub[i].getSubId())==std::stoi(subjectID)){
        return getDepartmentById(serviceDepSub[i].getDeptId());
      }
    }
    return department{};
  }

 //Metod koji vraca predmet a uzima id departmenta
   List<subject> getListSubjectDepartment(const std::string& depID){
    List<subject> jedan;
    
     for(int i=0;i<serviceDepSub.size();++i){
       
       if(std::stoi(serviceDepSub[i].getDeptId())==std::stoi(depID)){
        
         jedan.insert(getSubjectById(serviceDepSub[i].getSubId()));
      }
    }
    return jedan;
  }


  // Metod koji vraca department a uzima ID subjecta
 std::string getsubdep1(const std::string& subjeID)const{
    for(int i=0;i<subjectList.size();++i){
      if(subjectList[i].getId()==subjeID){
        return getDepartmentById(subjectList[i].getId());
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
  //Metod vraca date evala a uzima studentId i subjectId
std::string getStudentDate(const std::string& studentID,const std::string& subjectID){
   for(int i=0; i<serviceStudentsSubjectsTeachers.size();++i){
      if(serviceStudentsSubjectsTeachers[i].getStudId()==studentID && serviceStudentsSubjectsTeachers[i].getSubId()==subjectID)
        return serviceStudentsSubjectsTeachers[i].getDate();
    }
    return std::string{};
  }



  //Metod koji vraca ime departmen-a preko id-a//stoi ali treba izbrisati prvi red
  std::string getDepartmentById(const std::string& depID)const{
    for(int i=0;i<departmentList.size();++i){
      
      if(std::stoi(departmentList[i].getId())==std::stoi(depID)){
        return departmentList[i].getName();
      }
  
    }
    return std::string{"none"};
  }
  //Metod vraca ime+prezime teachera koji je na odredjenom predmetu
  subjectTeachers getSubjectTeacher(const std::string& subjectID)const{
    for(int i=0;i<serviceSubjectTeachers.size();++i){
      if(std::stoi(serviceSubjectTeachers[i].getSubId())==std::stoi(subjectID)){
        return serviceSubjectTeachers[i]; 
      }
    }
    return subjectTeachers{};
  }
  //Metod vraca predmet odredjenog profesora
    List<subject> getTeachersubject(const std::string& teacherID)const{
    List<subject> predmeti;
      for(int i=0;i<serviceSubjectTeachers.size();++i){
      if(std::stoi(serviceSubjectTeachers[i].getTeacherId())==std::stoi(teacherID)){
        predmeti.insert(getSubjectById(serviceSubjectTeachers[i].getSubId())); 
      }
    }
    return predmeti;
  }

  //Metod vraca teacher-a po ID-u
  teacher getTeacherById(const std::string &teacherID)const{
    for(int i=0;i<teacherList.size();++i){
      if(std::stoi(teacherList[i].getId())==std::stoi(teacherID)){
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
 
 // Ispis za mainmenu svi studenti
void menustudenti (){
  Vektor<student> vec(studentList.size());
  vec=studentList;
  vec.sort(Poprezimenus);
  std::cout << "Students: " << std::endl;
  for(auto i=0;i<vec.size();++i){
    std::cout <<"Id:"<< vec[i].getId() << ", "  << vec[i].getLastName()<< " "  << vec[i].getFirstName()<< " " << vec[i].getBirthdate()<< " " ;
    std::cout << vec[i].getEmail()<< " "  << vec[i].getGender()<< " "  << vec[i].getJmbg()<<  " ";
    std::cout << getDepartmentById(vec[i].getDepartmentId()) << std::endl;
  }
  std::cout<< std::endl;
}

  // ispis za mainMenu svi teacheri
void menuprofesori (){
  Vektor<teacher> vec(teacherList.size());
  vec=teacherList;
  vec.sort(Poprezimenut);
  std::cout << "Teachers: " << std::endl;
  for(auto i=0;i<vec.size();++i){
    std::cout <<"Id:"<< vec[i].getId() << ", "  << vec[i].getLastName()<< " "  << vec[i].getFirstName()<< " " << vec[i].getBirthdate()<< " " ;
    std::cout << vec[i].getEmail()<< " "  << vec[i].getGender()<< " "  << vec[i].getJmbg()<<  " " << vec[i].getTitle() << " ";
    std::cout << getDepartmentById(vec[i].getDepartmentId()) << std::endl;
  }
  std::cout<< std::endl;
}



 // Ispis za sve studente, ispisuje id, prezime, ime, department. provjereno
void svistudenti(const Vektor<student>& vec){
  for(int i=0;i<vec.size();++i){
    std:: cout<< "Id: "  <<vec[i].getId() << " \t" << "Last Name: "  << vec[i].getLastName() << " \t" << "First Name: "  << vec[i].getFirstName() <<" \t" << "Department: "  << getDepartmentById(vec[i].getDepartmentId()) << std::endl;
  }
}


// Ispis za sve studente sa nekog smjera. Provjereno
void studentisasmjera(const Vektor<student>& vec){
  for(auto i=0;i<vec.size();++i){
    std::cout<<"Id: "  << vec[i].getId() << " \t" <<"Last Name: "  << vec[i].getLastName() << " \t" << "First Name: "  << vec[i].getFirstName() << std::endl ;
  }
  std::cout << std::endl;
}

// ispis za sve profesore sa nekog smjera
void profesorisasmjera(const Vektor<teacher>& vec){
  for(auto i=0;i<vec.size();++i){
    std::cout<<"Id: "  << vec[i].getId() << " \t" <<"Last Name: "  << vec[i].getLastName() << " \t" << "First Name: "  << vec[i].getFirstName() << std::endl ;
  }
  std::cout << std::endl;
}

//ispis predmeta jednog studenta
void predmetistudenta(const std::string studId){
  std::cout << std::endl << "Student: " << std::endl;
  for(int i=0;i<studentList.size();++i)
  { if(studentList[i].getId()==studId)
    std::cout << studentList[i].getLastName() << " \t" << studentList[i].getFirstName()<<" \t" << studentList[i].getBirthdate()<<" \t" << studentList[i].getEmail() <<" \t" << studentList[i].getGender()<<" \t" << studentList[i].getJmbg() <<" \t"<< getStudentDepartment(studId) << std::endl;
  }
  std::cout<< "Subjects: " << std::endl;
 List<studentsSubjectsTeachers> listapredmeta=getAllSubjects(studId);

  for(int i=0;i<listapredmeta.size();++i)
  {std::cout<< getSubjectById(listapredmeta[i].getSubId()).getName()<< " \t" <<"Eval: " << getStudentEval(studId,listapredmeta[i].getSubId()) << " \t"<<"Date: " << getStudentDate(studId,listapredmeta[i].getSubId())<< std::endl;
  }

}

 //ispis studenta sa predmeta za meni
void menusvisapredmeta(const Vektor<student>& vec, const std::string& subId){
  std::cout <<std::endl << getSubjectById(subId).getName() << ":" << std::endl;
  for(int i=0;i<vec.size();++i){
std::cout << "Id: " << vec[i].getId() << ", "  << "Name: " << vec[i].getLastName() << " "<< vec[i].getFirstName() << " \t " << "Eval: ";
std::cout << getStudentEval(vec[i].getId(),subId) << std::endl;
  }
  std::cout << std::endl;
}
  // Ispis svih studenata sa nekog predmeta.  provjereno
void svisapredmeta(const Vektor<student>& vec, const std::string& subId){
  std::cout << getSubjectById(subId).getName() << std::endl;
  for(int i=0;i<vec.size();++i){
std::cout << "Id: " << vec[i].getId() << " "  << "Last name: " << vec[i].getLastName() << " " << "First Name: " << vec[i].getFirstName() << " " << "Eval: ";
std::cout << getStudentEval(vec[i].getId(),subId) << " " <<"Department: " << getStudentDepartment(vec[i].getId()) << " " << "Teacher: " ;
std::cout << getTeacherById(getSubjectTeacher(subId).getTeacherId()).getFirstName() << " ";
std::cout << getTeacherById(getSubjectTeacher(subId).getTeacherId()).getLastName() << std::endl;
  }
}


// Ispis svih profesora. provjereno
void sviprofesori(const Vektor<teacher> & vec){
  for(auto i=0; i<vec.size() ; ++i){
    std::cout << "Id: " << vec[i].getId()<< " \t" << "Last Name: " << vec[i].getLastName() << " \t" << "First Name: " << vec[i].getFirstName() << " \t" << "Department:" << getDepartmentById(vec[i].getDepartmentId()) << std::endl;
  }
}

// ispis jednog profesora
void jedanprofesor(const std::string teachId){
 std::cout << std::endl << "Teacher: " << std::endl;
  for(int i=0;i<teacherList.size();++i)
  { if(teacherList[i].getId()==teachId)
    std::cout << teacherList[i].getLastName() << " \t" << teacherList[i].getFirstName()<<" \t" << teacherList[i].getBirthdate()<<" \t" << teacherList[i].getEmail() <<" \t" << teacherList[i].getGender()<<" \t" << teacherList[i].getJmbg() <<" \t"<< getTeacherDepartment(teachId) << std::endl;
  }
  std::cout<< "Subjects: " << std::endl;
  List<subject> jedan=getTeachersubject(teachId);
  for(int i=0;i<jedan.size();++i)
  {std::cout<< jedan[i].getName()<< std::endl;
  }
 std::cout << std::endl;
}

// ispis svih predmeta. provjereno mozda napravit malo drugacije odvajanje
void svipredmeti(const Vektor<subject>& vec){
 for(int i=0;i<vec.size();++i)
{std::cout <<"Id: " << vec[i].getId() << " \t" << "Name: " << vec[i].getName() << " \t" << "Ects: " << vec[i].getEcts() << " \t" << "Abbreviation: " << vec[i].getAbb() << std::endl;
}std::cout << std::endl;
}

// ispis jednog predmeta po id
void jedanpredmet(const std::string subId){
  for(int i=0;i<subjectList.size();++i)
  { if(subjectList[i].getId()==subId)
    {std::cout << subjectList[i].getName()<<", " << getsubdep1(subId) <<std::endl;
      std::cout <<getTeacherById(getSubjectTeacher(subId).getTeacherId()).getFirstName() << " " ;
      std::cout << getTeacherById(getSubjectTeacher(subId).getTeacherId()).getLastName() << std::endl; 

    }
}}
// ispis svih departmenta provjereno
void svidepartmenti(){
  for(int i=0;i<departmentList.size();++i)
  {std::cout << "Id: " << departmentList[i].getId() << "\t" << "Name: " << departmentList[i].getName() << std::endl;}
}
void jedandepartment(const std::string depId){
  for(int i=0;i<departmentList.size();++i)
  {if(departmentList[i].getId()==depId)
    std::cout << departmentList[i].getName() <<std::endl;
  }
  std::cout <<"Subjects: "<<std::endl;
  List<subject> lista=getListSubjectDepartment(depId);
  for(int i=0;i<lista.size();++i)
  {
  std::cout << lista[i].getName() << " Ects: " <<lista[i].getEcts() << " " << lista[i].getAbb() << std::endl;
  }
  std::cout << std::endl << "Teachers: " << std::endl;
  List<teacher> jedinica=getTeacherfromDepartment(depId);
  for(int i=0;i<jedinica.size();++i)
  {
    std::cout << jedinica[i].getLastName() <<" " << jedinica[i].getFirstName() << " " << jedinica[i].getTitle() << std::endl;
  }
  std::cout<< std::endl;
}
void predmetisdepartmenta (const std::string& ID){
List<subject> jedan=getListSubjectDepartment(ID);
std::cout << "Department: "<< getDepartmentById(ID) << std::endl;
for(auto i=0; i<jedan.size(); ++i){
  
  std::cout << jedan[i].getId() <<" " <<jedan[i].getName()  << " Ects:  " <<  jedan[i].getEcts()  << std::endl;
  }
std::cout << std::endl;
}




  //kraj ispisa

  //ovde funkcije koje vracaju vektor za ispis prethodni

  //funkcija vraca sve depart vektor.
Vektor<department> Makesvidepartmenti(){
  Vektor<department> dp(departmentList.size());
  dp=departmentList;
  return dp;
}


  //funkcija vraca vektor za ispisivanje svih studenata.
  
Vektor<student> Makesvistudenti(){
  Vektor<student> st(studentList.size());
    st=studentList;
    st.sort(Poprezimenus);
    return st;
}

  //funkcija vraca vektor studenata sa smjera.
Vektor<student> Makestudentisasmjera(const std::string kojismjer){
  Vektor<student> st(studentList.size());
    for(int i=0;i<studentList.size();++i)
      { 
       if(std::stoi(studentList[i].getDepartmentId())==std::stoi(kojismjer))
        st.push(studentList[i]);
      }
  
      st.sort(Poprezimenus);
    return st;
  }
  //funkcija vrace vektor profesora sa smjera
  Vektor<teacher> Makeprofesorisasmjera(const std::string kojismjer){
  Vektor<teacher> st(teacherList.size());
    for(int i=0;i<teacherList.size();++i)
      { 
       if(std::stoi(teacherList[i].getDepartmentId())==std::stoi(kojismjer))
        st.push(teacherList[i]);
      }
  
      st.sort(Poprezimenut);
    return st;
  }


  //Funkcija vraca vektor svih studenata sa predmeta.
Vektor<student> Makesvisapredmeta(const std::string kojipredmet){
  Vektor<student> st(studentList.size());
   for(int i=0;i<studentList.size();++i){  
     List<studentsSubjectsTeachers> lista=getAllSubjects(studentList[i].getId());
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

std::string insertSubject(subject dummySub){
  for(int i=0;i<subjectList.size();++i){
    if(dummySub.getName()==subjectList[i].getName())
      return "none";
  }
  dummySub.setId(idSeter(subjectList)); //setujemo ID
  subjectList.insert(dummySub);
  return dummySub.getId();
}

std::string insertStudent(student dummyStud){
  if(!existJMBG(dummyStud.getJmbg())){
    dummyStud.setId(idSeter(studentList));//setujemo ID
    studentList.insert(dummyStud);
    return dummyStud.getId();
  }
  else{
    return "none";
  }
  
}

std::string insertTeacher(teacher dummyTeacher){
  if(!existJMBG(dummyTeacher.getJmbg())){
    dummyTeacher.setId(idSeter(teacherList));//setujemo ID
    teacherList.insert(dummyTeacher);
    return dummyTeacher.getId();
  }
  else{
    return "none";
  }
  
}







std::string insertDepartment(department tempDep){
  for(int i=0;i<departmentList.size();++i){
    if(departmentList[i].getName()==tempDep.getName())
      return "none";
  }
  tempDep.setId(idSeter(departmentList));
  departmentList.insert(tempDep);
  return tempDep.getId();
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
  
  bool existDep(const std::string &depID){
  for(int i=0;i<departmentList.size();++i){
    if(departmentList[i].getId()==depID)
      return true;
  }
  return false;
}
bool existStud(const std::string &studID){
  for(int i=0;i<studentList.size();++i){
    if(std::stoi(studentList[i].getId())==std::stoi(studID))
      return true;
  }
  return false;
}
bool existTeacher(const std::string &teacherID){
  for(int i=0;i<teacherList.size();++i){
    if(std::stoi(teacherList[i].getId())==std::stoi(teacherID))
      return true;
  }
  return false;
}
bool existSub(const std::string &subID){
  for(int i=0;i<subjectList.size();++i){
    if(std::stoi(subjectList[i].getId())==std::stoi(subID))
      return true;
  }
  return false;
}

//geteri LIsta
  List<student> getStudentList()const{return studentList;}

};




#endif
