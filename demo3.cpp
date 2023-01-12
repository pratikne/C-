// // // #include <iostream>
// // // using namespace std;

// // // int& fun()
// // // {
// // //     static int x = 10;
// // //     return x;
// // // }
 
// // // int main()
// // // {
// // //     fun() = 30; //valid
// // //     cout << fun();
// // //     return 0;
// // // }

// // #include <iostream>
// // using namespace std;
 
// // int fun(int& x) { return x; }
 
// // int main()
// // {
// //     cout << fun(10); //Error
// //     return 0;
// // }

// #include <iostream>
// using namespace std;
 
// void swap(char*& str1, char*& str2) //Valid
// {
//     char* temp = str1;
//     str1 = str2;
//     str2 = temp;
// }
 
// int main()
// {
//     char* str1 = "GEEKS";
//     char* str2 = "FOR GEEKS";
//     swap(str1, str2); //Valid
//     cout << "str1 is " << str1 << '\n';
//     cout << "str2 is " << str2 << '\n';
//     return 0;
// }

// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int x = 10;
//     int* ptr = &x;
//     int&* ptr1 = ptr; //Pointer to ref is not allowed
// }

// #include <iostream>
// using namespace std;
 
// int main()
// {
//     int* ptr = NULL;
//     int& ref = *ptr;
//     cout << ref << '\n'; //segmentation fault 
// }
#include <iostream>
using namespace std;
int& fun()
{
    int x = 10; //it should be static within func for this code to work or should be global var.
    return x;
}
 
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}