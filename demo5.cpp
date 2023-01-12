#include <iostream>
using namespace std;


template <typename T>
class Myclass
{

public:
    T a;

    Myclass() {}
    Myclass(T data)
    {
        a = data;
    }

    Myclass operator+(const Myclass &ab)
    {
        Myclass temp;
        temp.a = a + ab.a;
        cout << "temp : " << temp.a << endl;
        return temp;
    }
};

int main()
{
    Myclass<int> int1(10);
    Myclass<int> int2(20);
    Myclass<int> int3 = int1 + int2;

    //cout << int3 << endl;

    string s1 = "Pratik";
    string s2 = " Negi";

    Myclass<string> str1(s1);
    Myclass<string> str2(s2);
    Myclass<string> str3 = str1 + str2;

    //cout << str3 << endl;

    return 0;
}