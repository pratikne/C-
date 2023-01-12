/**@TOPIC ::: UNIQUR_PTR
 * @NOTES
 * 
 * 1. unique_ptr is one of smart ptr provided by C++11 tp prevent mmeory leaks
 * 2. It wraps a raw pointer in it and deallocates it once unique_ptr goes out of scope
 * 3. Similar to actual pointers, we can use -> and . on the object of unique_ptr
 * 4. Memory is deallocated in case of exceptions as well so no need to panic
 * 5. we can create array of objects of unique_ptr as well.
 * 
 * OPERATIONS
 * 
 * release, reset, swap, get
 * 
 * 
 *   ->, *. [] operators are overloaded within Smart pointer Class
 * 
 * Operators cannot be overloaded are :
 * [ ?: , . , :: , sizeof , .* , static_cast, dynamuc_cast, const_cast, reinterpret_cast , typeid] 
 */
#include <iostream>
#include <memory> //IMP for smart pointers
#include <exception>

using namespace std;

template <class T> // T is placeholder
class MyInt{
private: 
    T* ptr;

    void __cleanup__(){
        if(ptr != nullptr){
            delete ptr;
        }
    }

public:

    MyInt() : ptr(nullptr){} //default

    explicit MyInt(T* p){
        // explicit is used to avoid implicit type conversion of its instance
        ptr = p;
    }

    ~MyInt(){
        if(ptr != nullptr)
            delete ptr;
    }

    MyInt(const MyInt& obj) = delete; //Copy constructor is deleted
    MyInt& operator = (const MyInt& obj) = delete; //Copy assignment is deleted

    //Move constructor
    MyInt(MyInt&& dyingObj){
        ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    //Move assignment
    void operator = (MyInt&& dyingObj){
        //~MyInt();
        __cleanup__();
        ptr = dyingObj.ptr;
        dyingObj.ptr = nullptr;
    }

    T& operator * (){  //Dereferencing operator(*) overloaded
        return *ptr;
    }

    T* operator -> (){ 
        return ptr;
    }

    //overloading indexof operator
    T& operator [](int index){
        if(index < 0){
            //throw(new exception("Negative index exception"));
            throw("Negative index exception");
        }
        return ptr[index];
    }

    // void getdata(){
    //     cout << *ptr << endl;
    // }
};


int main(){
    int *p = new int(20);
    //MyInt myint = MyInt(p); //same as below
    MyInt<int> myint(p);
    cout << *myint << endl;
    //delete p;  //Error..No need of this as already handled by wrapping pointer in class..destructor will call delete
    return 0;
}
