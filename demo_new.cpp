#include <bits/stdc++.h>
using namespace std;

int main()
{
    // try
    // {
    //    throw 10;
    // }
    // catch (...)
    // {
    //     cout << "default exception\n";
    // }
    // catch (int param)
    // {
    //     cout << "int exception\n";
    // }

    int a = 10;
    int *p = &a;
    cout << a << endl; //10
    cout << *p << endl; //10

    p++;
    cout << a << endl; //10
    cout << *p << endl; //garbage 

    // int *q = new int(20);
    // cout << q << " " << *q << endl; //address 20 

    // q++;
    // cout << q << *q << endl; //address+4 garbage 
    // delete q;

    char arr[6] = "Hello"; //6th is null
    cout << arr << endl; //Hello till null
    cout << *arr << endl; //H
    printf("%s\n",arr); //Hello
    printf("%p\n",arr); //address of arr[0]

    char temp = 'z';
    char* ptr = &temp;
    cout << temp << endl;
    cout << ptr << endl; //prints till it detects NULL
    cout << *ptr << endl; //z

    void a = 10, b = 20;
    int c = (int)a + (int)b;
    cout << c << endl;

    return 0;
}

// error: '...' handler must be the last handler for its try block [-fpermissive]
//      catch (...)
//      ^~~~~