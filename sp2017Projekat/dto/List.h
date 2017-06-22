#ifndef LISTA_H_
#define LISTA_H_
template<typename T>
class Node{
public:
  T value_;
  Node* next_;
  Node(T value): value_(value),next_(nullptr){}



};

template<typename T>
class List{
private:
  Node<T>* first_;
  Node<T>* last_;
  unsigned int size_;
  void copyList(const List& dummy){
    if(first_!=nullptr){
      clearList();

    }
    if(dummy.first_){
      
      Node<T>* current=dummy.first_;
      Node<T>* temp=new Node<T> (current->value_);
      first_=temp;
      last_=first_;
      while(current->next_){
        current=current->next_;
        temp=new Node<T>(current->value_);
        last_->next_=temp;
        last_=last_->next_;
      }
size_=dummy.size_;
      
    }


  }
  void clearList(){
  Node<T>* temp;
  while(first_){
    temp=first_;
    first_=first_->next_;
    delete temp;
    }
  }
public:
  List():first_(nullptr),last_(nullptr),size_(0){}
  List(const List& dummy){
    this->copyList(dummy);
  }
  ~List(){clearList();}
    List& insertFirst(const T& dummy){
      Node<T>* temp=new Node<T>(dummy);
      if(first_==nullptr){
        first_=temp;
        last_=first_;
      }else{
      
      temp->next_=first_;
      first_=temp;
      }

      ++size_;
      return *this;
  }
  List& insertLast(const T& dummy){
    Node<T>* temp=new Node<T>(dummy);
    if(first_==nullptr){
      first_=temp;
      last_=first_;
    }else{
      last_->next_=temp;
      last_=last_->next_;
    }
    size_++;
  return *this;
  }
  List& deleteNode(const T& elem){
    Node<T>* current=first_;
    Node<T>* previous=nullptr;
    while(current){
      if(current->value_==elem){
        if(current==first_){
          first_=first_->next_;
        }else{
          previous->next_=current->next_;
        }
        delete current;
        --size_;
        break;
      }
    }
    previous=current;
    current=current->next_;
    return *this;
  }
  List& insert(const T& elem){
  if(first_==nullptr){
    first_=new Node<T>(elem);
    last_=first_;
  }else{
    
    if( elem < first_->value_){
      Node<T>* temp=new Node<T>(elem);
      temp->next_=first_;
      first_=temp;
    }else{
      Node<T>* current=first_;
      while(current!=last_){
        if(current->next_->value_>elem){
          Node<T>* temp=new Node<T>(elem);
          temp->next_=current->next_;
          current->next_=temp;
          break;
        }
        current=current->next_;
      }
      if(current==last_){
        Node<T>* temp=new Node<T>(elem);
        last_->next_=temp;
        last_=temp;
      }
    }
    
  }
  ++size_;
 return *this; 
  }
  T& operator[](int index){
    if(first_==nullptr)
      throw int(-1);
    Node<T>* current=first_;
    for(int i=0;i<index;++i){
      current=current->next_;
    }
    return current->value_;
  }
  T& operator[](int index)const{
    if(first_==nullptr && index >=size_)
      throw int(-1);
    Node<T>* current=first_;
    for(int i=0;i<index;++i){
      current=current->next_;
    }
    return current->value_;
  }
  int size()const{return size_;}
};



#endif
