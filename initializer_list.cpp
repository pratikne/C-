//https://www.geeksforgeeks.org/when-do-we-use-initializer-list-in-c/

#include <iostream>
using namespace std;

//1. Initializer List is used in initializing the data members of a class
class Point
{
private:
    int x;
    int y;

public:
    Point(int i = 0, int j = 0) : x(i), y(j) {}
    /*  The above use of Initializer list is optional as the
        constructor can also be written as:
        Point(int i = 0, int j = 0) {
            x = i;
            y = j;
        }
    */

    int getX() const { return x; }
    int getY() const { return y; }
};

//2. For initialization of non-static const data members: 
class Test
{
    const int t;

public:
    Test(int t) : t(t) {} // Initializer list must be used
    int getT() { return t; }
};

//3. For initialization of reference members: 
class Test2 {
    int &t;
public:
    Test2(int &t):t(t) {}  //Initializer list must be used
    int getT() { return t; }
};


//4. For initialization of member objects which do not have default constructor:
//5. For initialization of base class members
class A {
    int i;
public:
    A(int );
};



A::A(int arg) {
    i = arg;
    cout << "A's Constructor called: Value of i: " << i << endl;
}
 
// Class B is derived from A
class B: A {
public:
    B(int );
};
 
B::B(int x):A(x) { //Initializer list must be used
    cout << "B's Constructor called";
}

//6. When constructor’s parameter name is same as data member 
class P {
    int i;
public:
    P(int );
    int getI() const { return i; }
};
 
P::P(int i):i(i) { }  // Either Initializer list or this pointer must be used
/* The above constructor can also be written as
P::P(int i) {
    this->i = i;
}
*/
 
//7. For Performance reasons

int main()
{
    Point t1(10, 15);
    cout << "x = " << t1.getX() << ", ";
    cout << "y = " << t1.getY();

    Test t2(10);
    cout << t2.getT();

    int x = 20;
    Test2 t3(x);
    cout<<t3.getT()<<endl;
    x = 30;
    cout<<t3.getT()<<endl;

    B obj(10);

    P a(10);
    cout<<a.getI();

    return 0;
}

/* OUTPUT:
   x = 10, y = 15

   OUTPUT:
   10

   OUTPUT:
    20
    30
*/