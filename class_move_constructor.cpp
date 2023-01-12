#include <iostream>
#include <vector>
using namespace std;

class Demo{
public:
    int* p;
    Demo(int x){
        cout << "Const. called" << endl;
        p = new int;
        *p = x;
    }

    Demo(const Demo& d){ // Deep copy
        cout << "Copy Const. called" << endl;
        p = new int;
        *p = *d.p;
    }
    
    Demo(Demo&& d){
        /*Move constructor allows the resources owned by an r-value object to be moved into an l-value without creating its copy*/
        cout << "Move const. called" << endl;
        p = d.p;
        d.p = nullptr;
    }

    Demo& operator = (Demo&& d){
        /*Move assignment operator*/
        if(this != &d) //if not the same address
            delete this->p;
        this->p = d.p;
        d.p = nullptr;
        return *this;
    }

    ~Demo(){
        cout << "Dest. called" << endl;
        delete p;
        p = NULL;
    }

};

void fun1(int& ref){
    cout << "Normal ref." << endl;
}

void fun2(int&& ref){  
    cout << "R-value ref." << endl;
}

int global = 100;

int& fun3(){
    return global;
}

int* fun4(){
    return &global;
}

int main(){
    // Demo d1(10);
    // Demo d2(20);
    // Demo d3 = Demo(30);
    // Demo d4(d3); //Copy const. called
    // Demo d5(move(d3)); //explicitly called Move const.

    vector<Demo> v1;
    v1.push_back(move(Demo(10))); //explcit move called
    v1.push_back(10); //implicit move called

    int i = 10;

    //Reference is an alias for an already existing variable. Once it is initialized to a variable, 
    //it cannot be changed to refer to another variable. So, it's a const pointer.
    //No NULL and reassignment possible unlike pointers
    int &R = i; //Valid
    //int &A = 10; //Error
    const int& B = 10; //Works fine - allowed to bind const lvalue to rvalue

    int &&A = 10; //Valid - Rvalue assignment
    A++;
    cout << A << endl; //11

    fun1(R); 
    fun1(i);
    //fun1(100); //would have worked if former parameter would have been const int&

    int c = 10;
    int* p = &c;

    fun2(100);
    fun3() = 10; //Works fine as fun3( returns reference which is lvalue)
    // int& something = 10;
    //fun4() = &p; //Error as it will need lvalue to store 10

    /*R-Value is an expression that does not have any memory address and always on RHS
      L-Value is an expression with a memory address and can be on any side */

    return 0;
}

/**
 * 
 * 
 // =delete
 //  coding standard: disallow when not used
 = delete is a feature introduce in C++11. As per =delete it will not allowed to call that function.

T(void)                  = delete; // default ctor    (1)
~T(void)                 = delete; // default dtor    (2)
T(const T&)              = delete; // copy ctor       (3)
T(const T&&)             = delete; // move ctor       (4)
T& operator= (const T&)  = delete; // copy assignment (5)
T& operator= (const T&&) = delete; // move assignment (6)
 * 
 */