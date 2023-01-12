#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {100, 49, 59, 68, 370, 42};
    int size = sizeof(arr) / sizeof(arr[0]);
    set<int> s;
    set<int>::reverse_iterator rt;
    for (int i = 0; i < size; i++)
        s.insert(arr[i]);

    rt = s.rbegin();
    cout << "largest = " << *rt << endl;
    rt++;
    cout << "2nd largest = " << *rt << endl;

    string x;
    int b;
    cout << sizeof(x) << endl; // 32 bytes
    cout << sizeof(b) << endl; // 4 bytes
    return 0;
}