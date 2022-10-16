#include <iostream>
using namespace std;

class Complex
{
private:
    int a;
    int b;

public:
    Complex(int a, int b) //Parameterized Constructor
    {
        this->a = a;
        this->b = b;
        // this is a local object pointer in every instance member function
        // contains address of caller object
        // this* cannot be modified
        // use to refer caller object in member function
    }
    Complex(int x)  //Parameterized Constructor overloaded
    {
        a = x;
        b = 0;
    }
    Complex() //Default explicit Constructor - default implicit is overloaded
    {
        // Instance member function
        // can't be static
        // can't be overriden 
        // can't be virtual
        // can be overloaded
        // can be private
        // use to initialize the object
        // implicitly invoked when object is created
        a = 0;
        b = 0;
    }
    Complex(const Complex& k){ //copy constructor
        a = k.a;
        b = k.b;
    }

    Complex& operator = (const Complex& k){
        cout << "Copy Assignment operator called."<< endl;
        return *this;
    }

    Complex operator + (const Complex& k){ 
        // + operator overloaded
        Complex temp;
        temp.a = a + k.a;
        temp.b = b + k.b;
        return temp;
    }

    void show(){
        cout << a << " + " << b << "i" << endl;
    }

    ~Complex(){
        // Not static - as it belongs to instance and not class
        // No return type and input parameters
        // Hence, Can't be overloaded 
        // Can be overriden
        // Need to be virtual
        // can be private
        // invoked implicitly when object is going to destroy
        // defined to release resources allocated to an object
        cout << "Destructor called." << endl;
    }

    friend ostream& operator << (ostream& out, Complex c);
    //overloading extraction operator of class ostream
    //we cant create object of ostream so creating ref

    friend istream& operator >> (istream& out, Complex& c);
    //overloading insertion operator of class istream
    //we want to update Complex class, so passing ref

    friend void funadd(const Complex&);

    
};

ostream& operator << (ostream& out, Complex c){
    cout << "\na is " << c.a << "\n b is " << c.b << endl;
    return cout;
}

istream& operator >> (istream& out, Complex& c){
    cin >> c.a >> c.b ;
    return cin;
}

void funadd(const Complex& k){
    // It is the friend function of Complex
    // Not a member function of Complex class
    // declared in Complex class with friend keyword
    // can access any member of class to which it is friend (private also)
    // cannot be called with caller object
    // Not defined with :: (Membership label) as it doesnt belongs to class
    // entire class can also be frined of another class
    // member function of one class can be frined of another class 
    // operator overloaded functions can also be friend to another 

    cout << k.a + k.b << endl;
}

int main()
{
    Complex C1(3, 4);
    C1.show();
    // same as below
    Complex C1n = Complex(3, 4);
    C1n.show();

    Complex C2(5);
    C2.show();
    // same as below
    Complex C2n = 5;
    C2n.show();

    Complex C3;
    C3.show();

    Complex C4(C1); //copy constructor called
    C4.show();
    //same as below
    Complex C4n = C1;
    C4n.show();

    C4 = C1; //copy assignment operator called
    C4.show();

    Complex result = C1 + C4;
    result.show();

    funadd(result); //calling friend function

    Complex* p = new Complex(2,3); //Dynamic memory allocation
    p->show();

    Complex* parr = new Complex[10]; //Dynamically created array of Complex objects of sixe 10

    delete p; //IMP..release memory hole by p pointer
    p = NULL; //IMP..reinitialize NULL to p..so that it isn't wild

    delete[] parr; //IMP..release memory hold by parr pointer

    return 0;
}