#ifndef OPTIONS_H_
#define OPTIONS_H_
#include "baza.h"
// BOJE TEXTA - Definicije
const  std::string title("\033[0;32m");
const  std::string reset("\033[0m"); //resetuje boju
const std::string red("\033[1;31m");
const std::string green("\033[1;32m");

int rimtoarab(const std::string& broj){
  if(broj=="I")
    return 1;
  if(broj=="II")
    return 2;
  if(broj=="III")
    return 3;
  if(broj=="IV")
    return 4;
  if(broj=="V")
    return 5;
  if(broj=="VI")
    return 6;
  if(broj=="VII")
    return 7;
  if(broj=="VIII")
    return 8;
  if(broj=="IX")
    return 9;
  if(broj=="X")
    return 10;
  return 0;
}

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
  std::cout<<green<<"DEPARTMENTS LIST:"<<reset<<std::endl;
  temp.svidepartmenti();
  std::cout << "Insert subjects's department ID: ";
  std::cin >> input;
  system("clear");
  if(input!=std::string{})
  std::cout<<red<<"Invalid department ID!"<<reset<<"\n";
  
  }
  while(!temp.existDep(input));
  depSub tempDS;
  system("clear");
  std::cout<<"Subject's department is "<<red<<tempDS.getDeptId()<<reset<<"\n";
  //linkanje Departments - Subjects
    tempDS.setDeptId(input);
    tempDS.setSubId(temp.insertSubject(dummySub));
    input=std::string{};
    do{
    std::cout<<"Insert subject's study year("<<red<<"INSERT: 'I' or 'II'' or 'III' or 'IV'"<<reset<<"):";
    std::cin>>input;
    system("clear");
    if(input!="I" && input!="II" && input!="III" && input!="IV")
      std::cout<<red<<"Invalid study year format!"<<reset<<std::endl;
    }
    while(input!="I" && input!="II" && input!="III" && input!="IV");
    std::cout<<"Subject's study year is "<<red<<input<<reset<<"\n";
    tempDS.setStudyYear(input);
    int tY=rimtoarab(input);

    input=std::string{};
    do{
    std::cout<<"Insert subject's semester("<<red<<"INSERT: 'I' or 'II'' or 'III' or 'IV' or 'V' or 'VI' or 'VII' or 'VIII'"<<reset<<"):";
    std::cin>>input;
    system("clear");
    if((input!="I" && input!="II" && input!="III" && input!="IV" && input!="V" && input!="VI" && input!="VII" && input!="VII") || ( rimtoarab(input)!=(tY*2) && rimtoarab(input)!=((tY*2)-1)))
      std::cout<<red<<"Invalid semester format!"<<reset<<std::endl;
    }
    while(rimtoarab(input)!=(tY*2) && rimtoarab(input)!=((tY*2)-1));
    std::cout<<"Subject's semester is "<<red<<input<<reset<<"\n";
    tempDS.setSemester(input);
    temp.insertDepartmentsSubjects(tempDS);


}

void linkStudentSubject(Base& temp){
  studentsSubjectsTeachers tempSST;
  system("clear");
  
  std::string studentID{"uslovni"};
  do{
    if(studentID!="uslovni")
      std::cout << red << "Invalid ID!" << reset << std::endl;
  std::cout << "Select student (by id): \n";
  temp.svistudenti(temp.Makesvistudenti());
  std::cout <<"Your option: ";
  std::cin >> studentID;
  }while(!temp.existStud(studentID));
  tempSST.setStudId(studentID);
  
  system("clear");
  
  std::cout<< red << temp.getStudentById(studentID).getFirstName() << " " << temp.getStudentById(studentID).getLastName() << reset ; 
  std::cout << "\n";
  
  std::string input("uslovni");
  do{
  if(input!="uslovni")
    std::cout << red << "Invalid ID!" << reset << std::endl;
  std::cout << "Subject list: \n";
  temp.svipredmeti(temp.Makesvipredmeti());
  
  std::cout << "Your option: ";
  std::cin >> input;
  }while(!temp.existSub(input));
  tempSST.setSubId(input); 
  subjectTeachers dummy=temp.getSubjectTeacher(input); 
  tempSST.setTeacherId(dummy.getTeacherId());
  
  system("clear");
  input=std::string{"uslovni"};
  do{
  if(input!="uslovni")
    std::cout <<red << "Invalid evaluation(must be between 6 and 10)!" << reset << std::endl;
  std::cout << "Insert evaluation for chosen subject: ";
  std::cin >> input;

  }while(std::stoi(input)<6 || std::stoi(input)>10);
  
  tempSST.setEval(input);
  system("clear");
  std::cout << "Insert date(DD/MM/YY) when student got evaluated: ";
  std::cin >> input;
  tempSST.setDate(input);
  temp.insertSST(tempSST);

  
  
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
  std::cout<<green<<"DEPARTMENT'S LIST:"<<reset<<std::endl;
  temp.svidepartmenti();
  std::cout << "Insert teacher's department ID: ";
  std::cin >> input;
  system("clear");
  if(input!=std::string{})
  std::cout<<red<<"Invalid department ID!"<<reset<<"\n";
  
  }
  while(!temp.existDep(input));
  dummyTeacher.setDepartmentId(input);
  system("clear");
  std::cout<<"Teacher's department is "<<red<<temp.getDepartmentById(input)<<reset<<"\n";
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

void linkTeacherSubject(Base& temp){
system("clear");
std::string input{"uslov"};
subjectTeachers tempST;

do{
  system("clear");
if(input!="uslov")
  std::cout << red << "Invalid teacher ID!" << reset << std::endl;
std::cout << "Chose a profesor to link subjects to.\n";
temp.sviprofesori(temp.Makesviprofesori());
std::cout << "\nYour option: ";
std::cin >> input;
}while(!temp.existTeacher(input));
tempST.setTeacherId(input);
system("clear");
std::cout << red << temp.getTeacherById(input).getFirstName() + temp.getTeacherById(input).getLastName() << reset << std::endl;

input = "uslov";

do{
  system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid subject ID!" << reset << std::endl;
  std::cout << "Chose a subject to link to a teacher!\n";
  temp.svipredmeti(temp.Makesvipredmeti());
  std::cout << "\nYour option: ";
  std::cin >> input;
}while(!temp.existSub(input));
tempST.setSubId(input);
temp.insertSubjectTeacher(tempST);


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
        system("clear");
        break;
      case 2:
	      insertTeacherMenu(temp);
        system("clear");
        break;
      case 3:
	      insertSubjectMenu(temp);
        system("clear");
        break;
      case 4:
	      insertDepartmentMenu(temp);
        system("clear");
        break;
      case 5:
  	    linkStudentSubject(temp);
        system("clear");
        break;
      case 6:
        linkTeacherSubject(temp);
        system("clear");
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
//ODAVDE UPDATE

void editStudentFirstName(student& tempStudent){
  system("clear");
  std::string input;
  std::cout << "Student first name: " << red << tempStudent.getFirstName() << reset << std::endl;
  std::cout << "Change name to: ";
  std::cin >> input;
  tempStudent.setFirstName(input);
  system("clear");
  std::cout << "Name changed to: " << red << input << reset << std::endl;

}

void editStudentLastName(student& tempStudent){
  system("clear");
  std::string input;
  std::cout << "Student last name: " << red << tempStudent.getLastName() << reset << std::endl;
  std::cout << "Change name to: ";
  std::cin >> input;
  tempStudent.setLastName(input);
  system("clear");
  std::cout << "Name changed to: " << red << input << reset << std::endl;

}

void editStudentEmail(student& tempStudent){
  system("clear");
  std::string input;
  std::cout << "Student email: " << red << tempStudent.getEmail() << reset << std::endl;
  std::cout << "Change email to: ";
  std::cin >> input;
  tempStudent.setEmail(input);
  system("clear");
  std::cout << "Email changed to: " << red << input << reset << std::endl;

}
void editStudentSubject(student& tempStudent){
  system("clear");
  
  
}




void updateStudentMenu(student& tempStudent){
  int input=-1;
  bool prgLoop=true;
  do{
  system("clear");
  if(input<0 && input >4)
    std::cout << red << "Invalid option!" << reset << std::endl;
  std::cout << "Student currently edited: " << red << tempStudent.getFirstName() + " " + tempStudent.getLastName() << reset << std::endl;
  std::cout << "Insert what you want to edit: \n";
  std::cout << "1. Edit first name\n2. Edit last name\n3. Edit email\n4. Edit student subject\n0. Done editing";
  std::cout << "\nYour option: ";
  std::cin >> input;
  switch(input){
    case 1:
      editStudentFirstName(tempStudent);
      
      break;
    case 2:
      editStudentLastName(tempStudent);
      
      break;
    case 3:
      editStudentEmail(tempStudent);
      
      break;
    case 4:
      break;
    case 0:
      prgLoop=false;
      break;
    default:
      input=-1;
      break;
  }
  }while(prgLoop);

}


void updateStudent(Base& temp){
  system("clear");
  std::string input{"uslov"};
  do{
    system("clear");
    if(input!="uslov")
      std::cout <<red<<"Invalid ID!" << reset << std::endl;
    std::cout << "Insert student ID\n";
    temp.svistudenti(temp.Makesvistudenti());
    std::cin >> input;
  }while(!temp.existStud(input));
  student tempStudent=temp.getStudentById(input);
  updateStudentMenu(tempStudent);
  temp.setStudent(tempStudent);
}



// KRAJ
void updateDataMenu(Base& temp){
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
        updateStudent(temp);
        system("clear");
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
        updateDataMenu(temp);
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

