// https://pencilprogrammer.com/cpp-tutorials/strong-reference-vs-weak-reference/

#include <iostream>
#include <memory>
using namespace std;
 
class B; // Prototype of Class B
 
class A{
public:
    //referring pointer
    shared_ptr<B> BPtr;
    
    //constructor
    A(){
        cout << "Constructor A \n";
    }
    
    //destrutor
    ~A(){
        cout << "Destructor A \n";
    }
    
    //setter for the referring pointer
    void set_B(shared_ptr<B> b){
        BPtr = b;
    }
 
};
 
class B{
public:
    //referring pointer
    shared_ptr<A> APtr; 
    //referring pointer (replaced with weak pointer)
    //weak_ptr<A> APtr; //Solution for String Reference
    
    //constructor
    B(){
        cout << "Constructor B \n";
    }
    
    //destructor
    ~B(){
        cout << "Destructor B \n";
    }
    
    //setter for referring pointer
    void set_A(shared_ptr<A> a){
        APtr = a;
    }
 
};
 
int main()
{
    shared_ptr<A> a = make_shared<A>();
    shared_ptr<B> b = make_shared<B>();
 
    //Referring to each other
    a->set_B(b);
    b->set_A(a);
 
    return 0;
}