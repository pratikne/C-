/**@TOPIC :: SMART POINTERS (include <memory.h>)
 * @NOTES
 *
 * Smart pointer is a class which wraps a raw pointer so that its lifetime can be managed
 * Its fundamental job is to remove the chances of memory leak
 * It makes sure object is deleted if it is not referenced anymore
 * Crucial to RAII (Resource Acquisition is Initialization) programming strategy
 * -> main goal is to ensure that resource acquisition occurs at the same time that the object is initialized
 * -> resource for the object is created and made ready in single line of code
 * -> In practical terms, DM is allocated to stack allocated object whose destructor contains the code to delete or free the resource
 *
 * Types discussed below:
 *
 * <NOTE> : auto_ptr depreciated after C++11, unique_ptr came with similar functionality
 *        but with improved security
 *
 * 1) unique_ptr
 * allows only one owner of the underlying pointer
 * ownership can be moved but not copied or shared via move()
 * > copy is not allowed so = won't work
 * > up2 = up1       // No
 * > up2 = move(up1) // Yes ... up1 points to NULL now
 * Use when you want to have single ownership(exclusive) of the resource
 * size = 8 bytes
 *
 * 2) shared_ptr
 * allows multiple owner of same pointer ( Reference count is maintained via use_count() )
 * Use when you want to share ownership of a resource ( assign 1 raw pointer to multiple owners)
 * raw pointer is not deleted until all s_p owners have gone out of scope or have given up their ownerships
 * size = 16 bytes (2 pointer size -> 1 for object and 1 for shared control block that contains ref_count)
 *
 *
 * 3) weak_ptr
 * same as shared_ptr but ref count is not maintained (Actually weak ref count is maintained)
 * special case for use in conjuction with shared_ptr
 * use when you want to observe or read an object but do not require it to remain alive
 * use to break cyclic dependency references between shared_ptr
 *
 * weak_ptr<int> wk1;
 * {
 *      shared_ptr<int> sp1 = make_shared<int>(25); // 1 strong ref created
 *      wk1 = sp1;                                  // wp1 have 1 strong, 1 weak ref
 * } // sp1 got destroyed, but wp1 is still there with 1 weak ref
 * // weak ptr wont keep object alive but shared_ptr will
 *
 *
 **/

// Below is the implementation of smart pointer.
// no need to implement in C++ as we already have inbuilt smart pointers

#include <iostream>
#include <memory> //IMP for smart pointers
using namespace std;

template <class T>
class MyInt
{
private:
    T *data; // data is ptr
public:
    explicit MyInt(T *p)
    {
        data = p;
    }

    ~MyInt()
    {
        delete data;
    }

    T& operator*()
    {
        return *data;
    }

    T* operator->()
    {
        return data;
    }

    void fun()
    {
        cout << "Fun called" << endl;
    }
};

class Myclass
{
public:
    Myclass()
    {
        cout << "constructor" << endl;
    }
    ~Myclass()
    {
        cout << "destructor" << endl;
    }
};


void fun(unique_ptr<int>& u){
    cout << "HELLO" << *u << endl;
}

int main()
{
    int *p = new int(20);
    // MyInt myint = MyInt(p); //same as below
    MyInt<int> myint(p);
    cout << *myint << endl;

    unique_ptr<int> mit(new int(10)); // unique_ptr mit is created pointing to 10
    // OR better
    unique_ptr<int> mit1 = make_unique<int>(20); // unique_ptr mit1 is created pointing to heap memory storing 20

    fun(mit);

    unique_ptr<int[]> mit20 = make_unique<int[]>(20);
    // unique_ptr mit20 is created pointing to array of 20 ints

    shared_ptr<int> s2(new int(10)); // shared_ptr s2 is created pointing to 10
    // OR better
    shared_ptr<int> s1 = make_shared<int>(10); // shared_ptr s1 is created pointing to 10

    cout << "Size of unique ptr : " << sizeof(mit) << endl; // 8
    cout << "Size of shared ptr : " << sizeof(s2) << endl;  // 16

    /*IMP*/

    shared_ptr<int> s3 = s2; // s3 and s2 both sharing same memory location

    cout << "Use count : " << s3.use_count() << endl; // 2
    cout << "Use count : " << s2.use_count() << endl; // 2

    s3.reset();                                       // memory isnt freed as s2 still points to that location
    cout << "Use count : " << s3.use_count() << endl; // 0
    cout << "Use count : " << s2.use_count() << endl; // 1

    s2.reset();                                       // memory is freed since no one owns the memory now
    cout << "Use count : " << s3.use_count() << endl; // 0
    cout << "Use count : " << s2.use_count() << endl; // 0

    /*IMP*/

    weak_ptr<int> wp1(s1);
    cout << "Size of weak ptr : " << sizeof(wp1) << endl; // 16
    // weak_ptr is created as a copy of shared_ptr

    unique_ptr<int> mit2 = move(mit1);
    // mit1 is moved to mit2 and mit1 is now pointing to NULL(nullptr)
    // move transfers ownership
    // mit2 now owns memory
    // mit1 is set to nullptr

    int *n = mit.get();
    cout << *n << endl; //10
    // get returns address which is assigned to newly created pointer

    int *q = mit.release();
    // mit is moved to q and mit is pointing to NULL
    cout << *q << endl;

    // delete p;
    // Error..No need of this as already handled by wrapping pointer in class
    // destructor will call delete
    // same for mit, mit1, mit2

    delete n;
    // delete q; as q also beheves as unique ptr since it has an ownership

    weak_ptr<Myclass> wk1;
    {
        shared_ptr<Myclass> sp1 = make_shared<Myclass>(); // 1 strong ref created
        wk1 = sp1;                                  // wp1 have 1 strong, 1 weak ref
        cout << "Shared ptr getting deleted" << endl;
    }   // sp1 got destroyed, but wp1 is still there with 1 weak ref
    // weak ptr wont keep object alive but shared_ptr will

    cout << "Bye" << endl;
    return 0;
}
