#include <iostream>

// Ispis za sve studente, ispisuje id, prezime, ime, department.
void svistudenti(const Vektor<student>& vec){
  for(auto i=0;i<size();++i){i
    std:: cout<< "Id: "  <<vec[i].getId() << "\t" << "Last Name: "  << vec[i].getlastName() << "\t" << "First Name: "  << vec[i].getfirstName() <<"\t" << "Department: "  << getStudentDepartment(vec[i].getId()) << std::endl;
  }
}


// Ispis za sve studente sa nekog smjera.
void studentisasmjera(const Vektor<student>& vec){
  for(auto i=0;i<size();++i){
    std::cout<<"Id: "  << vec[i].getId() << "\t" <<"Last Name: "  << vec[i].getlastName() << "\t" << "First Name: "  << vec[i].getfirstName() << std::endl ;
  }
}


// Ispis svih studenata sa nekog predmeta.
void svisapredmeta(const Vektor<student>& vec, const std::string& subId){
  for(auto i=0;i<size();++i){
    std::cout << "Id: " <<vec[i].getId() << "\t" << "Last Name: "  << vec[i].getlastName() << "First Name: "  << vec[i].getfirstName() <<"\t"<< "Eval: "  << getStudentEval(vec[i].getId()) << "\t" << "Department: "  << getStudentDepartment(vec[i].getId()) << "Teacher: "  << getSubjectTeacher(subId) << std::endl ;
  }
}

// Ispis svih predmeta.
void svipredmeti(const Vektor<teacher> & vec){
  for(auto i=0; i<size() ; ++i){
    std::cout << "Id: " << vec[i].getId()<< "\t" << "Last Name: " << vec[i].getlastName() << "\t" << "First Name: " << vec[i].getfirstName() << "\t" << "Department:" << getDepartmentById(vec[i].getdepartmentId()) << std::endl;
  }
}
