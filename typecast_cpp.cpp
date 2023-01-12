/**CAST OPERATORS - Forcing one data type to another
 * 
 * A) STATIC_CAST
 * 
 * 1. performs implicit conversions
 * 2. checks for error in compile time
 * 3. char* to int* is allowed in C-style but not with static_cast
 * 4. it also avoids cast from derived to private base pointer
 * 5. use for all upcast (derived to base) but not for confused downcast (use dynamic_cast there)
 * (upcast - > from derived to base class or downcast - > from base to derived class).
 * 6. preferred when converting to void* OR from void*
 * 7. easy to locate
 * 
 * If it fails, compilation error comes
 * 
 * B) DYNAMIC_CAST
 * 
 * 1. The dynamic_cast is a runtime cast operator used to perform conversion of one type variable to another only on class pointers and references. 
 * 2. It means it checks the valid casting of the variables at the run time, and if the casting fails, it returns a NULL value. Dynamic casting is based on RTTI (Runtime Type Identification) mechanism.
 * 3. works only for polymorphic classes
 * 
 * return NULL when casting a pointer
 * throw bad_cast exception when casting references
 * 
 * 
 * C) REINTERPRET_CAST
 * 
 * The reinterpret_cast type casting is used to cast a pointer to any other type of pointer whether the given pointer belongs to each other or not. It means it does not check whether the pointer or the data pointed to by the pointer is the same or not. 
 * 1. it can perform dangerous conversions coz it can typecast any pointer to any other
 * 
 * D) CONST_CAST
 * The const_cast is used to change or manipulate the const behavior of the source pointer. It means we can perform the const in two ways: setting a const pointer to a non-const pointer or deleting or removing the const from a const pointer.
 * use to cast away the constness of variables
 */

#include <iostream>  
using namespace std;  

int disp(int *pt)  
{  
    return (*pt * 10);  
}  

int main(){
    float f = 2.4f;
    int a;

    a = f; //2 (implicit casting of float to int)
    // char - sort int -> int -> unsigned int -> long int -> float -> double -> long double, etc.

    // Implicit Type Casting should be done from low to higher data types. Otherwise, it affects the fundamental data type, which may lose precision or data, and the compiler might flash a warning to this effect.

    double x = 1.2;
    int xi = (int) x; // explicit casting from double to int

    //static_cast<kisme type me cast karna hai> (kisko cast karna hai)
    int ai = static_cast<int>(f);

    int b = 10;
    void* v = static_cast<void*>(&b);
    int* t = static_cast<int*>(v);


    const int num = 50;  
    const int* pt = num; // get the address of num  
      
    // use const_cast to chnage the constness of the source pointer  
    int* ptr = const_cast <int*> (pt);  
    cout << " The value of ptr cast: " << disp(ptr);  

    return 0;
}