#include <bits/stdc++.h>
using namespace std;
/** ACCESS MODIFIERS -> supports ENCAPSULATION....data hiding for increased security
 * 1) PRIVATE   (own class- yes, derived/child class- no, outside class-no)
 * 2) PUBLIC    (own class- yes, derived/child class- yes, outside class-yes)
 * 3) PROTECTED (own class- yes, derived/child class- yes, outside class-no)
**/
class Student{
    string name;   //private member(by def)
    public:   //by default....attributes/data members are private...can be accessed within class
    int age;
    bool gender;

    Student(){
        //cout<<"DEF CONST CALLED"<<endl;
    }

    Student(string nam, int age, bool gender){
        cout<<"PARA CONSTR CALLED"<<endl;
        name = nam;  //if diff var...ok...if same...this-> is must for pointing to self object member
        this->gender = gender;
        this->age = age;
    }

    void setData(string s){
        name = s;
    }

    void getData(){
        cout<<"Name = "<<name<<endl;
        cout<<"Gender = "<<gender<<endl;
        cout<<"Age = "<<age<<endl;
    }

    Student( Student &A){
        cout<<"COPY CONSTRUCTOR CALLED"<<endl; 
        //DEEP COPY done...orginal object is copied physically and new obj will hold that copy.
        //If new obj values are changed, wont affect original one and vice versa as pointers point to different memory having same value
        name = A.name;
        gender = A.gender;
        age = A.age;
    }

    ~Student(){  //nothing can be passed..nor can be returned
        cout<<"DESTRUCTOR CALLED"<<endl;  //called whenever objects are destructed...called at returning from main function
    }

    /**OPERATOR OVERLOADING**/
    bool operator == (Student &A){
        if(name == A.name and gender == A.gender and name == A.name){
            return true;
        }
        else
            return false;
    }

    private:
    void func(){
        cout<<"PRIVATE METHOD"<<endl;
    }
};

class NewStudent : public Student{
//This means Student class ke public and protected attributes as well as methods can be used by this child/derived class
};

int main(){

    Student A;
    //A.name = "Pratik";
    A.setData("Pratik");
    A.age = 23;
    A.gender = true;

    A.getData();
/**
    Student arr[3];
    string temp;
    for (int i = 0; i < 3; i++)
    {
        cout<<"Age : ";
        cin >> arr[i].age;
        cout<<"Gender : ";
        cin >> arr[i].gender;
        cout<<"Name : ";
        cin >> temp;
        arr[i].setData(temp);    
    }

    for (int i = 0; i < 3; i++){
        arr[i].getData();
    }
**/
    Student B("Ritik",18,true);  //calling constructor for data initialization

    B.getData();

    Student C; //calling default const

    Student D(B);  
    //calling copy constructor (bydefalut prsent)...does shallow copy.....(if and only if manual cc is not made)
    //pointers are shared
    D.getData();

    Student E = B; //calling copy constr in another way
    E.getData();

    if(A == E){   //here we will use operator overloading as == doesnt work for comparing two objects
        cout<<"Same"<<endl;
    }
    else{
        cout<<"Different"<<endl;
    }
    //E.func(); //error.as func is private

    return 0;
}
