#ifndef OPTIONS_H_
#define OPTIONS_H_
#include "baza.h"
// BOJE TEXTA - Definicije
const  std::string title("\033[0;32m");
const  std::string reset("\033[0m"); //resetuje boju
const std::string red("\033[1;31m");


void insertDepartmentMenu(Base& temp){
  system("clear");
  department dummyDep;
  std::string input;
  std::cout << "Insert department's name: ";
  std::cin >> input;
  dummyDep.setName(input);
  system("clear");
  std::cout << "Department's name is " << red << input << reset<< "\n";
  temp.insertDepartment(dummyDep);
}


void insertSubjectMenu(Base& temp){
  system("clear");
  subject dummySub;
  std::string input;
  std::cout << "Insert subject's name: ";
  std::cin >> input;
  dummySub.setName(input);
  system("clear");
  std::cout << "Subject's name is " << red << input << reset<< "\n";
  std::cout << "Insert subject's ECTS: ";
  std::cin >> input;
  dummySub.setEcts(input);
  system("clear");
  std::cout << "Subject's ECTS is " << red << input <<reset<< "\n";
  std::cout << "Insert subject's abbreviation: ";
  std::cin >> input;
  dummySub.setAbb(input);
  system("clear");
  std::cout << "Subject's abbreviation is " << red << input << reset << "\n";
  input=std::string{};
  do{
  //temp.svidepartmenti();
  std::cout << "Insert subjects's department ID: ";
  std::cin >> input;
  system("clear");
  if(!(input==std::string{}))
  std::cout<<red<<"Invalid department ID!"<<reset<<"\n";
  
  }
  while(!temp.existDep(input));
  depSub tempDS;
  //linkanje Departments - Subjects
  //tempDS.setDeptId();
 // temp.setSubId(); treba getovati ID subjecta da se proslijedi u setSubId()
  system("clear");
  std::cout<<"Subject's department is "<<red<<tempDS.getDeptId()<<reset<<"\n";
  temp.insertSubject(dummySub);




}




void insertTeacherMenu(Base& temp){
  system("clear");
  teacher dummyTeacher;
  std::string input;
  std::cout << "Insert teacher's first name: ";
  std::cin >> input;
  dummyTeacher.setFirstName(input);
  system("clear");
  std::cout << "Teacher's first name is " << red << input << reset<< "\n";
  std::cout << "Insert teacher's last name: ";
  std::cin >> input;
  dummyTeacher.setLastName(input);
  system("clear");
  std::cout << "Teacher's last name is " << red << input <<reset<< "\n";
  std::cout << "Insert teacher's birth date (FORMAT: DD/MM/YY): ";
  std::cin >> input;
  dummyTeacher.setBirthdate(input);
  system("clear");
  std::cout << "Teacher's birth date is " << red << input << reset << "\n";
  input=std::string{};
  do{
  if(input!=std::string{})
    std::cout <<red <<"Invalid JMBG.Must contain 13 numbers! " <<reset<<std::endl;
  std::cout << "Insert teacher's JMBG: ";
  std::cin >> input;
  system("clear");
  }while(input.length()!=13 || temp.existJMBG(input));
  dummyTeacher.setJmbg(input);
  system("clear");
  std::cout << "Teacher's JMBG is "<< red << input << reset<<"\n";
  std::cout << "Insert teacher's email: ";
  std::cin >> input;
  dummyTeacher.setEmail(input);
  system("clear");
   std::cout << "Teacher's email is "<< red << input << reset<<"\n";
  std::cout << "Insert teacher's gender(M/F): ";
  input=std::string{};
  do{
    if(input!=std::string{}){
      std::cout<<red<<"Invalid gender format. Must be 'M' or 'F'!"<<reset<<std::endl;
    }
    std::cout<<"Insert teacher's gender: ";
    std::cin>>input;
    system("clear");

  }
  while(input!="M" && input!="F");
  dummyTeacher.setGender(input);
  system("clear");
  std::cout << "Teacher's gender is "<< red << input << reset<<"\n";
  std::cout << "Insert teacher's title: ";
  std::cin >> input;
  dummyTeacher.setTitle(input);
  system("clear");
  std::cout<< "Teacher's title is "<<red<<input<<reset<<"\n";
  input=std::string{};
  do{
  //temp.svidepartmenti();
  std::cout << "Insert teacher's department ID: ";
  std::cin >> input;
  system("clear");
  if(!(input==std::string{}))
  std::cout<<red<<"Invalid department ID!"<<reset<<"\n";
  
  }
  while(!temp.existDep(input));
  dummyTeacher.setDepartmentId(input);
  system("clear");
  std::cout<<"Student's department is "<<red<<temp.getDepartmentById(input)<<reset<<"\n";
  temp.insertTeacher(dummyTeacher);




}



void insertStudentMenu(Base& temp){
  system("clear");
  student dummyStud;
  std::string input;
  std::cout << "Insert student's first name: ";
  std::cin >> input;
  dummyStud.setFirstName(input);
  system("clear");
  std::cout << "Student's first name is " << red << input << reset<< "\n";
  std::cout << "Insert student's last name: ";
  std::cin >> input;
  dummyStud.setLastName(input);
  system("clear");
  std::cout << "Student's last name is " << red << input <<reset<< "\n";
  std::cout << "Insert student's birth date (FORMAT: DD/MM/YY): ";
  std::cin >> input;
  dummyStud.setBirthdate(input);
  system("clear");
  std::cout << "Student's birth date is " << red << input << reset << "\n";
  input=std::string{};
  do{
  if(input!=std::string{})
    std::cout <<red <<"Invalid JMBG.Must contain 13 numbers! " <<reset<<std::endl;
  std::cout << "Insert student's JMBG: ";
  std::cin >> input;
  system("clear");
  }while(input.length()!=13 || temp.existJMBG(input));
  dummyStud.setJmbg(input);
  system("clear");
  std::cout << "Student's JMBG is "<< red << input << reset<<"\n";
  std::cout << "Insert student's email: ";
  std::cin >> input;
  dummyStud.setEmail(input);
  system("clear");
   std::cout << "Student's email is "<< red << input << reset<<"\n";
  std::cout << "Insert student's gender(M/F): ";
  input=std::string{};
  do{
    if(input!=std::string{}){
      std::cout<<red<<"Invalid gender format. Must be 'M' or 'F'!"<<reset<<std::endl;
    }
    std::cout<<"Insert student's gender: ";
    std::cin>>input;
    system("clear");

  }
  while(input!="M" && input!="F");
  dummyStud.setGender(input);
  system("clear");
  std::cout << "Student's gender is "<< red << input << reset<<"\n";
  input=std::string{};
  do{
  temp.svidepartmenti();
  std::cout << "Insert student's department ID: ";
  std::cin >> input;
  system("clear");
  if(!(input==std::string{}))
  std::cout<<red<<"Invalid department ID!"<<reset<<"\n";
  
  }
  while(!temp.existDep(input));
  dummyStud.setDepartmentId(input);
  system("clear");
  std::cout<<"Student's department is "<<red<<temp.getDepartmentById(input)<<reset<<"\n";
  temp.insertStudent(dummyStud);




}

void insertDataMenu(Base& temp){
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
   std::cout << "Enter what do you want to insert:\n\n";
    std::cout << "1. Insert students\n2. Insert teachers\n3. Insert subjects\n4. Insert departments\n5. Link subjects to students\n6. Link subjects to teachers \n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        insertStudentMenu(temp);
        break;
      case 2:
	insertTeacherMenu(temp);
        break;
      case 3:
	insertSubjectMenu(temp);
        break;
      case 4:
	insertDepartmentMenu(temp);
        break;
      case 5:
        break;
      case 6:
        break;
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!"<<reset<<std::endl;
        break;
    }
  }
}
void updateDataMenu(){
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
   std::cout << "Enter what do you want to update:\n\n";
    std::cout << "1. Update student\n2. Update teacher\n3. Update subject\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!"<<reset<<std::endl;
        break;
    }
  }
}

void readDataMenu(){
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
   std::cout << "Enter what do you want to read:\n\n";
    std::cout << "1. Read students\n2. Read teachers\n3. Read subjects\n4. Read departments\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        break;
      case 2:
        break;
      case 3:
        break;
      case 4:
        break;
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!"<<reset<<std::endl;
        break;
    }
  }
}




void mainMenu(Base& temp){ 
  int optionNum;
  bool prgLoop=true;
  system("clear");
  while(prgLoop){
  
  std::cout<<"SELECT AN OPTION(insert option number):\n";
  std::cout<<"\n\n1. Insert data\n2. Update data\n3. Read data\n0. Exit\n\n";

    std::cout<<"\rYour option: ";
    std::cin>>optionNum;
    switch(optionNum){
      case 1:
        insertDataMenu(temp);
        system("clear");
        break;
      case 2:
        updateDataMenu();
        system("clear");
        break;
      case 3:
        readDataMenu();
        system("clear");
        break;
      case 0:
        std::cout<<"Thanks for using our database!\nSee you again! :)\n";
        prgLoop=false;
        break;
      default:
        system("clear");
        std::cout<<red<<"Invalid option!\nTry again!\n"<<reset;
        break;
    }
  }
}


#endif

