#include <bits/stdc++.h>
using namespace std;
/****OOPS 4 features (A PIE)
 * A->Abstarction
 * P->Polymorphism
 * I->Inheritance
 * E->Encapsulation
 ****/

/** ACCESS MODIFIERS -> supports ABSTRACTION within ENCAPSULATED format....data hiding for increased security
 * 1) PRIVATE (own class- yes, derived/child class- no, outside class-no)
 * 2) PUBLIC (own class- yes, derived/child class- yes, outside class-yes)
 * 3) PROTECTED (own class- yes, derived/child class- yes, outside class-no)
**/

/**POLYMORPHISM (Many forms)
 * 
 * 1) COMPILE TIME
 *      a) Function Overloading
 *      b) operator Overloading
 * 2) RUN TIME
 *      a) Function overriding using Virtual keyword
 **/

class College{ //Displaying method overloading
    public:
    void fun(){
        cout<<"Function with NO args"<<endl;
    }
    void fun(int x){
        cout<<"Function with Int arg"<<endl;
    }
    void fun(double x){
        cout<<"Function with Double arg"<<endl;
    }
};

class Complex{
    private:
    int real, img;
    public:

    Complex(){ //default const.
        //DO nothing
    }

    Complex(int real, int img){ //para. const. -> setter
        this->real = real;
        this->img = img;
    }

    Complex operator + (Complex const &obj){ //operator overloading
        Complex res;  //will call default const on line 43
        res.real = real + obj.real;
        res.img = img + obj.img;
        return res;
    }

    void getdata(){   //getter
        cout<< real << " + i" << img <<endl;
    }

};

class Base{
    public:
    virtual void print(){
        cout<<"Base class print function"<<endl;
    }
};

class Child : public Base{
    public:
    void print(){
        cout<<"Child class print function"<<endl;
    }
};

int main(){
    College obj;
    obj.fun();
    obj.fun(1);
    obj.fun(1.20);

    Complex c1(12,12),c2(13,13);

    Complex c3 = c1 + c2;

    c3.getdata();

    Base b1,*ptr1;
    //ptr1 = &b1;

    Child ch1,*ptr2;
    //ptr2 = &ch1;
    ptr1 = &ch1;   //pointer is of Base class but at runtime, we bind child obj address to it...so virtual at runtime will take child class print function..if virtual not used....it will take base class methods as pointer is of that class

    ch1.print();
    b1.print();
    ptr1->print();
    //ptr2->print();

    return 0;
}