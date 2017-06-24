#include "parsiranje.h"
using namespace std;



void separate(int &i,string rijecText, string& rijec){
  while(rijecText[i]!=','&& rijecText[i]!='\0'){rijec.push_back(rijecText[i]); i++;}
  i++;i++;
}

//student
void parsiraj(List<student> &r,string l){
  int i=0;
  string id, firstName, lastName, birthdate, email, gender, jmbg, department;
  
  separate(i,l,id);
  separate(i,l,firstName);
  separate(i,l,lastName);
  separate(i,l,birthdate);
  separate(i,l,email);
  separate(i,l,gender);
  separate(i,l,jmbg);
  separate(i,l,department);
  r.insert(student(id,firstName,lastName,birthdate,email,gender,jmbg,department));
}

//teacher
void parsiraj(List<teacher> &r,string l){
  int i=0;
  string id, firstName, lastName, birthdate, email, gender, jmbg, title, department;
  
  separate(i,l,id);
  separate(i,l,firstName);
  separate(i,l,lastName);
  separate(i,l,birthdate);
  separate(i,l,email);
  separate(i,l,gender);
  separate(i,l,jmbg);
  separate(i,l,title);
  separate(i,l,department);
  r.insert(teacher(id,firstName,lastName,birthdate,email,gender,jmbg,title,department));
}


//subject

void parsiraj(List<subject> &r,string l){
  int i=0;
  string id, Name, ects, abb;
  
  separate(i,l,id);
  separate(i,l,Name);
  separate(i,l,ects);
  separate(i,l,abb);
  r.insert(subject(id,Name,ects,abb));
}
//department

void parsiraj(List<department> &r,string l){
  int i=0;
  string id, Name;
  
  separate(i,l,id);
  separate(i,l,Name);
  r.insert(department(id,Name));
}


//department_subject
void parsiraj(List<depSub> &r,string l){
  int i=0;
  string did,sid,year,sem;
  
  separate(i,l,did);
  separate(i,l,sid);
  separate(i,l,year);
  separate(i,l,sem);
  r.insert(depSub(did,sid,year,sem));
}

//studetnsSubjectsTeachers
void parsiraj(List<studentsSubjectsTeachers> &r,string l){
  int i=0;
  string sid,suid,tid,eval,date;
  
  separate(i,l,sid);
  separate(i,l,suid);
  separate(i,l,tid);
  separate(i,l,eval);
  separate(i,l,date);
  r.insert(studentsSubjectsTeachers(sid,suid,tid,eval,date));
}


//subjectTeachers
void parsiraj(List<subjectTeachers> &r,string l){
  int i=0;
  string sid,tid;
  
  separate(i,l,sid);
  separate(i,l,tid);
  r.insert(subjectTeachers(sid,tid));
}

//Omogucivanje rada sa datotekom students.txt
void stutxt(List<student>& b){
  ofstream st;
  st.open("../db/students.txt");
  for(auto i=0;i<b.size();++i){
    st << b[i].getId() <<", "<< b[i].getFirstName()<< ", "  << b[i].getLastName() << ", "  << b[i].getBirthdate() << ", "  << b[i].getEmail() << ", "  << b[i].getGender() << ", " << b[i].getJmbg() << ", " << b[i].getDepartmentId()  <<std::endl; 
  }
  st.close();
} 


//Omogucivanje rada sa datotekom departments.txt
void deptxt(List<department>& b){
  ofstream st;
  st.open("../db/departments.txt");
  for(auto i=0;i<b.size();++i){
    st << b[i].getId() <<", "<< b[i].getName()<< std::endl; 
  }
  st.close();
} 


//Omogucivanje rada sa datotekom departments-subjects.txt
void depsubtxt(List<depSub>& b){
  ofstream st;
  st.open("../db/departments-subjects.txt");
  for(auto i=0;i<b.size();++i){
    st << b[i].getDeptId() <<", "<< b[i].getSubId()<< ", " << b[i].getStudyYear() << ", "<< b[i].getSemester() << std::endl; 
  }
  st.close();
} 


//Omogucivanje rada sa datotekom students-subjects-teachers.txt
void studsubtchtxt(List<studentsSubjectsTeachers>& b){
  ofstream st;
  st.open("../db/students-subjects-teachers.txt");
  for(auto i=0;i<b.size();++i){
    st << b[i].getStudId() <<", "<< b[i].getSubId()<< ", " << b[i].getTeacherId() << ", "<< b[i].getEval() << ", " << b[i].getDate()  << std::endl; 
  }
  st.close();
} 


//Omogucivanje rada sa datotekom subjects.txt
void subtxt(List<subject>& b){
  ofstream st;
  st.open("../db/subjects.txt");
  for(auto i=0;i<b.size();++i){
    st << b[i].getId() <<", "<< b[i].getName()<< ", " << b[i].getEcts() << ", "<< b[i].getAbb() << std::endl; 
  }
  st.close();
} 


//Omogucivanje rada sa datotekom subjects-teachers.txt
void subtchtxt(List<subjectTeachers>& b){
  ofstream st;
  st.open("../db/subjects-teachers.txt");
  for(auto i=0;i<b.size();++i){
    st << b[i].getSubId() <<", "<< b[i].getTeacherId()<< std::endl; 
  }
  st.close();
} 


//Omogucivanje rada sa datotekom teachers.txt
void tchhtxt(List<teacher>& b){
  ofstream st;
  st.open("../db/teachers.txt");
for(auto i=0;i<b.size();++i){
    st << b[i].getId() <<", "<< b[i].getFirstName()<< ", "  << b[i].getLastName() << ", "  << b[i].getBirthdate() << ", "  << b[i].getEmail() << ", "  << b[i].getGender() << ", " << b[i].getJmbg() << ", " << b[i].getTitle() << ", " << b[i].getDepartmentId() <<std::endl; 
  }
  st.close();
} 




