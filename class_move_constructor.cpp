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
    Demo(const Demo& d){
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
    int &R = i; //Valid
    //int &A = 10; //Error

    int &&A = 10; //Valid - Rvalue assignment
    A++;
    cout << A << endl; //11

    fun1(R);
    fun1(i);

    fun2(100);

    /*R-Value is an expression that does not have any memory address 
      L-Value is an expression with a memory address*/

    return 0;
}