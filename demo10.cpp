#include <iostream>
using namespace std;


// int main(){
//     int i;
//     char* arr[] = {"C", "C++", "Java","Go"};
//     char*(*ptr)[4] = &arr;
//     cout << ++(*ptr)[2];

//     return 0;
// }

// //Output:
// //ava

// int main(){
//     int n = 5;
//     void *p = &n;
//     int* pi = static_cast<int*>(p);
//     cout << *pi << endl;
//     return 0;
// }

// // 5

int main(){
    int x = 5;
    int y = 6;
    y = x++ * ++x; //5 * 7
    cout << x << " " << y << endl; // 7 35

    x = 5;
    y = ++x * x++; //6 * 7
    cout << x << " " << y << endl; // 7 42

    signed int adsd = -2;
    if(adsd=5){
        cout << "Updated value : " << adsd << endl; //5
    }
    cout << "Updated value : " << adsd << endl; //5

    int* ptr = 0;
    cout << &ptr << endl; // 0xgfhej
    cout << ptr << endl; // 0
    cout << *ptr << endl; // runtime error

    return 0;
}