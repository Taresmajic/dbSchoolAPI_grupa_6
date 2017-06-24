#ifndef _PARSIRANJE_H
#define _PARSIRANJE_H
#include "List.h"
#include "student.h"
#include "teacher.h"
#include "osoba.h"
#include "subject.h"
#include "department.h"
#include "depSub.h"
#include "studentsSubjectsTeachers.h"
#include "subjectTeachers.h"
#include <fstream>
#include <iostream>




void separate(int&,std::string,std::string&);
void parsiraj(List<student>&,std::string);
void parsiraj(List<teacher>&,std::string);
void parsiraj(List<subject>&,std::string);
void parsiraj(List<department>&,std::string);
void parsiraj(List<depSub>&,std::string);
void parsiraj(List<studentsSubjectsTeachers>&,std::string);
void parsiraj(List<subjectTeachers>&,std::string);
void stutxt(List<student>&);
void deptxt(List<department>&);
void depsubtxt(List<depSub>&);
void depsubtchtxt(List<studentsSubjectsTeachers>&);
void subtxt(List<subject>&);
void subtch(List<subjectTeachers>&);
void tchhtxt(List<teacher>&);











#endif
