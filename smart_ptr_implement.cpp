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
 */
#include <iostream>
#include <memory> //IMP for smart pointers
using namespace std;

template <class T> // T is placeholder
class MyInt{
private: 
    T* ptr;
public:
    explicit MyInt(T* p){
        ptr = p;
    }

    ~MyInt(){
        delete ptr;
    }

    T& operator * (){  //Dereferencing operator overloaded
        return *ptr;
    }

    T* operator -> (){ 
        return ptr;
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
