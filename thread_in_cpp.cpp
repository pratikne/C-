/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <thread>
using namespace std;

void fun1(int& arg){
    cout << "Hi, I am fun1()" << endl;
    arg++;
    cout << arg << endl;
}

void fun2(){
    cout << "Hi, I am fun2()" << endl;
}

int main(){
    int val = 10;

    thread t1(fun1,ref(val));
    //IMP ::: If needed to be passed by ref in threads, then use ref(arg) use
    thread t2(fun2);
    
    t1.join();
    t2.join();
    
    cout << val << endl;

    return 0;
}
