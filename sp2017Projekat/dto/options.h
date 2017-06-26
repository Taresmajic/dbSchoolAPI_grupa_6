#ifndef OPTIONS_H_
#define OPTIONS_H_
#include "baza.h"
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
  std::string confirm;
  bool confirmStatus=true;
  do{
  std::cout << "Insert department's name: ";
  std::cin >> input;
  dummyDep.setName(input);
  system("clear");

  do{
    std::cout << "Department's name is " << red << input << reset<< "\n";
    std::cout << "Do you confirm this input? (Y/N):";
    std::cin >> confirm;
    system("clear");
    if((confirm!="Y" && confirm!="N")){
    std::cout <<red <<"Invalid confirm option! (Please insert 'Y' or 'N')!"<<reset<<std::endl;
  }
 
  }
  while(confirm!="Y" && confirm!="N");
  if(confirm=="N"){
    confirmStatus=false;
    std::cout<<green<<"Insert new value!\n"<<reset<<std::endl;
  }
   else
    confirmStatus=true;
  }
   while(!confirmStatus);
  std::cout<<"Department's name is "<<red<<input<<reset<<std::endl;
 system("clear");
  std::cout<<green<<"DEPARTAMENT HAS BEEN SUCCESSFULLY INSERTED!\n"<<reset;


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
    std::cout<<red << "Insert semester odd or evene coresponding with semester year: "<< reset << std::endl;
    std::cout<<"("<<red<<"INSERT: 'I' or 'II'' or 'III' or 'IV' or 'V' or 'VI' or 'VII' or 'VIII'"<<reset<<"):";
    std::cin>>input;
    system("clear");
    if((input!="I" && input!="II" && input!="III" && input!="IV" && input!="V" && input!="VI" && input!="VII" && input!="VII") || ( rimtoarab(input)!=(tY*2) && rimtoarab(input)!=((tY*2)-1)))
      std::cout<<red<<"Invalid semester format!"<<reset<<std::endl;
    }
    while(rimtoarab(input)!=(tY*2) && rimtoarab(input)!=((tY*2)-1));
    std::cout<<"Subject's semester is "<<red<<input<<reset<<"\n";
    tempDS.setSemester(input);

std::cout<<green<<"Subject's information:\n"<<reset;
  temp.getTempSubject(dummySub,tempDS.getStudyYear(),tempDS.getSemester());
 std::string confirm;
  do{
  std::cout<<red<<"DO YOU WANT TO PROCEED?('Y' or 'N'):"<<reset; 
  std::cin>>confirm;
  if(confirm=="N")
    insertSubjectMenu(temp);
  
  if(confirm=="Y")
    temp.insertSubject(dummySub);
 temp.insertDepartmentsSubjects(tempDS);
  }  
  while(confirm!="Y" && confirm!="N");
  system("clear");
  std::cout<<green<<"SUBJECT HAS BEEN SUCCESSFULLY INSERTED!\n"<<reset;
}

void linkStudentSubject(Base& temp){
  studentsSubjectsTeachers tempSST;
  system("clear");
  
  bool uslov=true;
  std::string studentID;
  std::string input;
while(uslov){
  studentID="uslovni";
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
  
  input="uslovni";
  do{
  if(input!="uslovni")
    std::cout << red << "Invalid ID!" << reset << std::endl;
  std::cout << "Subject list: \n";
  temp.svipredmeti(temp.Makesvipredmeti());
  
  std::cout << "Your option: ";
  std::cin >> input;
  }while(!temp.existSub(input));
  tempSST.setSubId(input); 
  if(temp.existSST(tempSST)){
    system("clear");
    std::cout << red << "This student already has this subject!" << reset << std::endl;
    std::cout << "Do you want to exit(Y/N): ";
    std::string yes_no;
    std::cin >> yes_no;
    bool yes_no_test=true;
    while(yes_no_test)
    if(yes_no=="Y")
      return;
    else{
      if(yes_no!="N"){
        std::cout << red << "Must be Y or N!" << reset << std::endl;
      }else yes_no_test=false;
      
    }
    uslov=true;
  }else uslov = false;
  
}
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
   input=std::string{};
  
   do{
    if(input!=std::string{}){
    std::cout<<red<<"Invalid gender format. Must be 'M' or 'F'!"<<reset<<std::endl;
    }

    std::cout << "Insert teacher's gender(M/F): ";
    std::cin>>input;
    system("clear");

  }while(input!="M" && input!="F");
  
  
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
  std::cout<<green<<"Teacher's information:\n"<<reset;
  temp.getTempTeacher(dummyTeacher);
 std::string confirm;
  do{
  std::cout<<red<<"DO YOU WANT TO PROCEED?('Y' or 'N'):"<<reset; 
  std::cin>>confirm;
  if(confirm=="N")
    insertTeacherMenu(temp);
  
  if(confirm=="Y")
    temp.insertTeacher(dummyTeacher);
  }  
  while(confirm!="Y" && confirm!="N");
  system("clear");
  std::cout<<green<<"TEACHER HAS BEEN SUCCESSFULLY INSERTED!\n"<<reset;



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
    input=std::string{};
  do{
  std::cout << "Insert student's gender(M/F): ";
    if(input!=std::string{}){
      std::cout<<red<<"Invalid gender format. Must be 'M' or 'F'!"<<reset<<std::endl;
    }
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
  std::cout<<green<<"Student's information:\n"<<reset;
  temp.getTempStudent(dummyStud);
 std::string confirm;
  do{
  std::cout<<red<<"DO YOU WANT TO PROCEED?('Y' or 'N'):"<<reset; 
  std::cin>>confirm;
  if(confirm=="N")
    insertStudentMenu(temp);
  
  if(confirm=="Y")
    temp.insertStudent(dummyStud);
  }  
  while(confirm!="Y" && confirm!="N");
  system("clear");
  std::cout<<green<<"STUDENT HAS BEEN SUCCESSFULLY INSERTED!\n"<<reset;


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
bool uslov = true;
while(uslov){
do{
  input="uslov";
  system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid subject ID!" << reset << std::endl;
  std::cout << "Chose a subject to link to a teacher!\n";
  temp.svipredmeti(temp.Makesvipredmeti());
  std::cout << "\nYour option: ";
  std::cin >> input;  
}while(!temp.existSub(input));

tempST.setSubId(input);

if(temp.existSubjectTeacher(tempST)){
  system("clear");
  std::cout <<red<< "Chosen subject already has a teacher!"<<reset<< std::endl;
  std::cout << "Do you want to abort(Y/N): ";
  bool yes_no_usl=true;
  while(yes_no_usl){
  std::string yes_no;
  std::cin >> yes_no;
  if(yes_no=="Y"){
    return;
  }else{
    if(yes_no=="N"){
    yes_no_usl=false;
    }else{
      std::cout << red << "Must be Y or N!\n"<<reset;
     }
  }
  }
}
}
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
  	    linkStudentSubject(temp);
       
        break;
      case 6:
        linkTeacherSubject(temp);
        
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

void editStudentFirstName(Base& temp,student& tempStudent){
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



void editStudentSubject(Base& temp,student& tempStudent){
  system("clear");
  studentsSubjectsTeachers tempSST;
    std::string input("uslovni");
  do{
    if(input!="uslovni"){
      std::cout << red << "Invalid ID\n" << reset;
    }
    system("clear");
    
    std::cout << "Select subject you want to edit:\n";
    temp.predmetistudenta(tempStudent.getId()); 
    std::cout << "Yout input: ";
    std::cin >> input;

  }while(!temp.existSub(input));
tempSST.setSubId(input);
tempSST.setStudId(tempStudent.getId());
tempSST=temp.getSST(tempSST);
int tempEval;
bool usl=true;
system("clear");  
while(usl){
    
    std::cout << "Previous evaluation: " << red << tempSST.getEval() << reset << std::endl;
    std::cout << "New evaluation: ";
    std::cin >> tempEval;
    if(tempEval<6 || tempEval>10){
      system("clear");
      std::cout << red << "Invalid input! Eval must be between 6 and 10!" << reset << std::endl;
    }
    else usl=false;
  }
tempSST.setEval(std::to_string(tempEval));

system("clear");
std::cout << "Insert the date of the evaluation: ";
std::cin >> input;
tempSST.setDate(input);
system("clear");
bool yes_no_usl=true;
while(yes_no_usl){

std::cout << "New evaluation: "<< red << tempSST.getEval()<<reset << "\tNew evaluation date: " << red << tempSST.getDate() << reset << std::endl;
std::cout << "Do you want to acept the changes? (Y/N): ";
std::cin >> input;
if(input=="Y"){
  temp.setSST(tempSST);
  return;
}else{
  if(input!="N"){
    std::cout << red << "Invalid option!" << reset << std::endl;
  }else yes_no_usl=false;
}

}

}

void deleteStudent(Base& temp,student &tempStudent){
	
	temp.eraseStudent(tempStudent.getId()); //proslijedio id u erase metod
  std::cout<<green<<"Student has been successfully deleted!\n"<<reset;
}


void updateStudentMenu(Base& temp,student& tempStudent){
  int input=-1;
  bool prgLoop=true;
  do{
  system("clear");
  if(input<0 && input >4)
    std::cout << red << "Invalid option!" << reset << std::endl;
  std::cout << "Student currently edited: " << red << tempStudent.getFirstName() + " " + tempStudent.getLastName() << reset << std::endl;
  std::cout << "Insert what you want to edit: \n";
  std::cout << "1. Edit first name\n2. Edit last name\n3. Edit email\n4. Edit student subject\n5. Delete student\n0. Done editing";
  std::cout << "\nYour option: ";
  std::cin >> input;
  switch(input){
    case 1:
      editStudentFirstName(temp,tempStudent);
      
      break;
    case 2:
      editStudentLastName(tempStudent);
      
      break;
    case 3:
      editStudentEmail(tempStudent);
      
      break;
    case 4:
      editStudentSubject(temp,tempStudent);
      break;
    case 5:
      deleteStudent(temp,tempStudent);
      return;
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
  updateStudentMenu(temp,tempStudent);
  temp.setStudent(tempStudent);
}


void updateTeacherFirstName(Base& temp,teacher& tempTeacher){
  system("clear");
  std::string input;
  std::cout << "Teacher first name: " << red << tempTeacher.getFirstName() << reset << std::endl;
  std::cout << "Change name to: ";
  std::cin >> input;
  tempTeacher.setFirstName(input);
  system("clear");
  std::cout << "Name changed to: " << red << input << reset << std::endl;

  temp.setTeacher(tempTeacher);
}

void updateTeacherLastName(Base& temp,teacher& tempTeacher){
  system("clear");
  std::string input;
  std::cout << "Teacher last name: " << red << tempTeacher.getLastName() << reset << std::endl;
  std::cout << "Change name to: ";
  std::cin >> input;
  tempTeacher.setLastName(input);
  system("clear");
  std::cout << "Name changed to: " << red << input << reset << std::endl;

  temp.setTeacher(tempTeacher);
}


void updateTeacherEmail(Base& temp,teacher& tempTeacher){
  system("clear");
  std::string input;
  std::cout << "Teacher email: " << red << tempTeacher.getEmail() << reset << std::endl;
  std::cout << "Change email to: ";
  std::cin >> input;
  tempTeacher.setEmail(input);
  system("clear");
  std::cout << "Email changed to: " << red << input << reset << std::endl;

  temp.setTeacher(tempTeacher);
}

void updateTeacherTitle(Base& temp,teacher& tempTeacher){
  system("clear");
  std::string input;
  std::cout << "Teacher title: " << red << tempTeacher.getTitle() << reset << std::endl;
  std::cout << "Change title to: ";
  std::cin >> input;
  tempTeacher.setTitle(input);
  system("clear");
  std::cout << "Title changed to: " << red << input << reset << std::endl;
  temp.setTeacher(tempTeacher);
}


void updateTeacherDepartment(Base& temp,teacher& tempTeacher){
  system("clear");
  std::cout << "Previous teacher department: " <<red<< temp.getDepartmentById(tempTeacher.getDepartmentId()) << reset << std::endl;
  
  std::string input{"Uslovni"};
  do{
    if(input!="Uslovni")
      std::cout << red << "Invalid ID!" << reset << std::endl;
  std::cout << "Department ID you want to asign: \n";
  temp.svidepartmenti();
  std::cout << "Your option: ";
  std::cin >> input;
  system("clear");
  }while(!temp.existDep(input));
  tempTeacher.setDepartmentId(input);
  temp.setTeacher(tempTeacher);
 
}

void deleteTeacher(Base& temp, teacher tempTeacher){
	bool status=true;
	std::string yes_no="Y";
	status=temp.eraseTeacher(tempTeacher.getId());
	system("clear");
	if(!status)
		std::cout<<red<<"That teacher can't be delete becouse it's linked with subject!\n"<<reset;
  else
    std::cout<<green<<"Teacher has been successfully deleted!\n"<<reset;
}

void updateTeacherMenu(Base& temp){
  teacher tempTeacher;
  system("clear");
  
  std::string input{"Uslovni"};
  do{
    if(input!="Uslovni")
      std::cout << red << "Invalid ID!" << reset << std::endl;
  std::cout << "Insert witch teacher you want to edit: \n";
  temp.sviprofesori(temp.Makesviprofesori());
  std::cout << "Your option: ";
  std::cin >> input;
  system("clear");
  }while(!temp.existTeacher(input));
  tempTeacher=temp.getTeacherById(input);
  
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
    std::cout <<  "Teacher eddited: " << red << tempTeacher.getFirstName() + " " + tempTeacher.getLastName() << reset << std::endl;
    std::cout << "Enter what do you want to update:\n\n";
    std::cout<< "1. Update teacher first name\n2. Update teacher last name\n3. Update teacher title\n4. Update teacher email\n5. Update teacher department\n6. Delete teacher\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        updateTeacherFirstName(temp,tempTeacher);
        system("clear");
        break;
      case 2:
        updateTeacherLastName(temp,tempTeacher);
        system("clear");
        break;
      case 3:
        updateTeacherTitle(temp,tempTeacher);
        system("clear");
        break;
      case 4:
        updateTeacherEmail(temp,tempTeacher);
        system("clear");
        break;
      case 5:
        updateTeacherDepartment(temp,tempTeacher);
        system("clear");
        break;
      case 6:
	      deleteTeacher(temp,tempTeacher);
        return;
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


void updateSubjectName(Base& temp,subject& tempSubject){
  system("clear");
  std::string input;
  std::cout << "Subject name: " << red << tempSubject.getName() << reset << std::endl;
  std::cout << "Change name to: ";
  std::cin >> input;
  tempSubject.setName(input);
  system("clear");
  std::cout << "Name changed to: " << red << input << reset << std::endl;

  temp.setSubject(tempSubject);
}

void updateSubjectDepartment(Base& temp,subject& tempSubject){
  system("clear");
  depSub tempDepSub=temp.getSubjectInfo(tempSubject.getId());

  std::string input;
  do{
  std::cout << "Subject department: " << red << temp.getSubjectDepartment(tempSubject.getId()).getName() << reset << std::endl;
  std::cout << "Department to: \n";
  temp.svidepartmenti();
  std::cin >> input;
  tempDepSub.setDeptId(input);
  system("clear");
  std::cout << "Deapartment changed to: " << red << temp.getDepartmentById(input) << reset << std::endl;
  }while(!temp.existDep(input));
  system("clear");
  temp.setDepSub(tempDepSub);
}

void updateSubjectEcts(Base& temp,subject& tempSubject){
  system("clear");
  

  std::string input("uslovni");
  do{
    if(input!="uslovni")
      std::cout << red << "Invalid insert!" << reset << std::endl;
  std::cout << "Subject ects: " << red << tempSubject.getEcts() << reset << std::endl;
  std::cout << "Ects to: \n";
  std::cin >> input;
  system("clear");
  }while((input!="6")&&(input!="7")&&(input!="8")&&(input!="9"));
 system("clear");
  tempSubject.setEcts(input);
  temp.setSubject(tempSubject);
  std::cout << "Ects changed to: " << red << tempSubject.getEcts() << reset << std::endl;
}

void updateSubjectSS(Base& temp,subject& tempSubject){
  
  depSub tempDepSub;
  system("clear");
  std::string input;  
 do{
    std::cout<<"Insert subject's study year("<<red<<"INSERT: 'I' or 'II'' or 'III' or 'IV'"<<reset<<"):";
    std::cin>>input;
    system("clear");
    if(input!="I" && input!="II" && input!="III" && input!="IV")
      std::cout<<red<<"Invalid study year format!"<<reset<<std::endl;
    }
    while(input!="I" && input!="II" && input!="III" && input!="IV");
    system("clear");    
    std::cout<<"Subject's study year is "<<red<<input<<reset<<"\n";
    tempDepSub.setStudyYear(input);
    
    int tY=rimtoarab(input);
  do{
    std::cout<<"Insert subject's semester("<<red<<"INSERT: 'I' or 'II'' or 'III' or 'IV' or 'V' or 'VI' or 'VII' or 'VIII'"<<reset<<"):";
    std::cin>>input;
    system("clear");
    if((input!="I" && input!="II" && input!="III" && input!="IV" && input!="V" && input!="VI" && input!="VII" && input!="VII") || ( rimtoarab(input)!=(tY*2) && rimtoarab(input)!=((tY*2)-1)))
      std::cout<<red<<"Invalid semester format!"<<reset<<std::endl;
    }
    while(rimtoarab(input)!=(tY*2) && rimtoarab(input)!=((tY*2)-1));
  system("clear");  
  std::cout<<"Subject's semester is "<<red<<input<<reset<<"\n";
  tempDepSub.setSemester(input);
  temp.setDepSub(tempDepSub);



  
}


void deleteSubject(Base &temp, subject & tempSub){
	temp.eraseSubject(tempSub.getId()); //proslijedi id za brisanje
  std::cout<<green<<"Subject has been successfully deleted!\n"<<reset;
}



void updateSubjectMenu(Base& temp){
  subject tempSubject;
  system("clear");
  
  std::string input{"Uslovni"};
  do{
    if(input!="Uslovni")
      std::cout << red << "Invalid ID!" << reset << std::endl;
  std::cout << "Insert witch subject you want to edit: \n";
  temp.svipredmeti(temp.Makesvipredmeti());
  std::cout << "Your option: ";
  std::cin >> input;
  system("clear");
  }while(!temp.existSub(input));
  tempSubject=temp.getSubjectById(input);
  
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
    std::cout <<  "Subject eddited: " << red << tempSubject.getName()<< reset << std::endl;
    std::cout << "Enter what do you want to update:\n\n";
    std::cout<< "1. Update subject name\n2. Update subject department\n3. Update subject ects\n4. Update year and semester\n5. Delete subject\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        updateSubjectName(temp,tempSubject); 
        break;
      case 2:
        updateSubjectDepartment(temp,tempSubject); 
        break;
      case 3:
        updateSubjectEcts(temp,tempSubject);
        break;
      case 4:
        updateSubjectSS(temp,tempSubject); 
        break;
      case 5:
	deleteSubject(temp,tempSubject);
  return;
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
        break;
      case 2:
        updateTeacherMenu(temp);
        break;
      case 3:
        updateSubjectMenu(temp);
    
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
void readstudent(Base& temp){
system("clear");
Vektor<student> vec=temp.Makesvistudenti();
temp.svistudenti(vec);
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid student's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert student's ID: " << std::endl;
  temp.svistudenti(temp.Makesvistudenti());
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existStud(input));
system("clear");
temp.predmetistudenta(input);
std::cout << std::endl;

}
void readallstudents(Base& temp){
  system("clear");
  temp.menustudenti();
}
void readstudentssubject(Base& temp){
system("clear");
Vektor<subject> vec=temp.Makesvipredmeti();
temp.svipredmeti(vec);
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid subject's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert subject's ID: " << std::endl;
  temp.svipredmeti(temp.Makesvipredmeti());
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existStud(input));
system("clear");
Vektor<student> veci=temp.Makesvisapredmeta(input);
temp.menusvisapredmeta(veci,input);

}

void readstudentsdep(Base& temp){
system("clear");
Vektor<department> vec=temp.Makesvidepartmenti();
temp.svidepartmenti();
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid department's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert department's ID: " << std::endl;
  temp.svidepartmenti();
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existDep(input));
system("clear");
std::cout<<temp.getDepartmentById(input)<<std::endl;
Vektor<student> veci=temp.Makestudentisasmjera(input);
temp.studentisasmjera(veci);
}




void readstudentmenu(Base& temp){
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
   std::cout << "Enter what do you want to read:\n\n";
    std::cout << "1. Read student\n2. Read all students\n3. Read students from subject\n4. Read students from departments\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        readstudent(temp);
        break;
      case 2:
        readallstudents(temp);
        break;
      case 3:
        readstudentssubject(temp);
        break;
      case 4:
        readstudentsdep(temp);
        break;
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!\nTry Again!\n"<<reset<<std::endl;
        break;

}}}
void readteacher(Base& temp){
system("clear");
Vektor<teacher> vec=temp.Makesviprofesori();
temp.sviprofesori(vec);
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid teacher's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert teacher's ID: " << std::endl;
  temp.sviprofesori(temp.Makesviprofesori());
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existTeacher(input));
system("clear");
temp.jedanprofesor(input);
}
void readallteachers(Base& temp){
  system("clear");
  temp.menuprofesori();
}
void readteacherdep(Base& temp){
system("clear");
Vektor<department> vec=temp.Makesvidepartmenti();
temp.svidepartmenti();
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid department's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert department's ID: " << std::endl;
  temp.svidepartmenti();
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existDep(input));
system("clear");
std::cout << temp.getDepartmentById(input)<<std::endl;
Vektor<teacher> veci=temp.Makeprofesorisasmjera(input);
temp.profesorisasmjera(veci);


}

void readteachermenu(Base& temp){
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
   std::cout << "Enter what do you want to read:\n\n";
    std::cout << "1. Read teacher\n2. Read all teachers\n3. Read teachers from department\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        readteacher(temp);
        break;
      case 2:
        readallteachers(temp);
        break;
      case 3:
        readteacherdep(temp);
        break;  
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!\nTry Again!\n"<<reset<<std::endl;
        break;

}}}
void readsubject(Base& temp){
system("clear");
Vektor<subject> vec=temp.Makesvipredmeti();
temp.svipredmeti(vec);
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid subject's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert subject's ID: " << std::endl;
  temp.svipredmeti(temp.Makesvipredmeti());
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existSub(input));
system("clear");
std::cout << "Subject: " << std::endl;
temp.jedanpredmet(input);
}

void allsubject (Base& temp){
system("clear");
std::cout <<"Subjects:" << std::endl;
Vektor<subject> vec=temp.Makesvipredmeti();
temp.svipredmeti(vec);
}

void readdepsub(Base& temp){
system("clear");
Vektor<department> vec=temp.Makesvidepartmenti();
temp.svidepartmenti();
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid department's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert department's ID: " << std::endl;
  temp.svidepartmenti();
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existDep(input));
system("clear");
temp.predmetisdepartmenta(input);


}



void readsubjectmenu(Base& temp){
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
   std::cout << "Enter what do you want to read:\n\n";
    std::cout << "1. Read subject\n2. Read all subjects\n3. Read subjects from department\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        readsubject(temp);
        break;
      case 2:
        allsubject(temp);
        break;
      case 3:
        readdepsub(temp); 
        break;  
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!\nTry Again!\n"<<reset<<std::endl;
        break;

}}}
void readdepartment(Base& temp)
{system("clear");

temp.svidepartmenti();
std::string input("uslov");

do{
   system("clear");
  if(input!="uslov")
    std::cout << red << "Invalid department's ID!\n" << reset << std::endl;
  
  std::cout<<  "Insert department's ID: " << std::endl;
  temp.svidepartmenti();
  std::cout << "\nYour option: ";
  std::cin >> input;
  
}while(!temp.existDep(input));
system("clear");
temp.jedandepartment(input);
}
void alldepartments(Base& temp)
{system("clear");
  std::cout << "Departments: " <<std::endl;
  temp.svidepartmenti();
  std::cout << std::endl;

}

void readdepartmentmenu(Base& temp){
  bool prgLoop=true;
  int opt;
  system("clear");
  while(prgLoop){
   std::cout << "Enter what do you want to read:\n\n";
    std::cout << "1. Read department\n2. Read all departments\n0. Go back\n\n";
    std::cout << "Your option: ";
    std::cin >> opt;
    switch(opt){
      case 1:
        readdepartment(temp);
        break;
      case 2:
        alldepartments(temp);
        break;
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!\nTry Again!\n"<<reset<<std::endl;
        break;


    }
  }
}

void readDataMenu(Base& temp){
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
        readstudentmenu(temp);
        system("clear");
        break;
      case 2:
        readteachermenu(temp);
        system("clear");
        break;
      case 3:
        readsubjectmenu(temp);
        system("clear");
        break;
      case 4:
        readdepartmentmenu(temp);
        system("clear");
        break;
      case 0:
        return;
        break;
      default:
      system("clear");
      std::cout << red <<"Invalid option!\nTry again!\n"<<reset<<std::endl;
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
        readDataMenu(temp);
        system("clear");
        break;
      case 0:
        std::cout<<"Thanks for using our database!\nSee you again! :)\n";
        temp.alltxt();
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

