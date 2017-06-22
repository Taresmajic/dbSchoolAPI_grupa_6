#include "List.h"
#include "student.h"
#include "teacher.h"
#include "osoba.h"
#include "subject.h"
#include "department.h"
#include "depSub.h"
#include "studentsSubjectsTeachers.h"
#include "subjectTeachers.h"

#include<string>
#include<fstream>
#include<iostream>
using namespace std;



void separate(int &i,string rijecText, string& rijec){
  while(rijecText[i]!=','&& rijecText[i]!='\0'){rijec.push_back(rijecText[i]); i++;}
  i++;
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
int main (){
  List<teacher> tch;
  fstream fajl("../db/teachers.txt");
  string ko;
  while(getline(fajl,ko))
    parsiraj(tch,ko);
  cout<<tch[0];

}
