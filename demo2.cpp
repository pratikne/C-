#include<bits/stdc++.h>
using namespace std;

int a(){
    cout<<"a";
    return 0;
}

int b(){
    cout<<"b";
    return 0;
}

int main(){
    if(a() || b()){
        cout<<"main";
    }  //ab

    if(a() && b()){
        cout<<"main";
    } //a

    if(a() & b()){
        cout<<"main";
    } //ab

    if(a() | b()){
        cout<<"main";
    } //ab

    if(a() ^ b()){
        cout<<"main";
    } //ab

    string str;
    cout<<"["<<str<<"]"<<str.size()<<endl; //size is 0

    vector<int> v(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    cout<< v.size() <<endl; //5 , donno why ?

    cout << (1.0f + 2.0f == 3.0f) <<endl; //1
    cout << (1 + 2 == 3) << endl;  //1

    char* arr = "Hello"; 
    printf("%ld\n",strlen(arr)); //5
    // Above is String literal...we can't modify it ..Read only
    // arr[0] = 'P' ;//Error - Segmentation fault

    char arr2[] = "Hello"; // H e l l o \0
    // Above is C-strings are 1D array of characters and are NULL terminated
    // we can modify individual char.
    arr2[0] = 'C'; //Works fine
    puts(arr2); //Cello
    printf("%ld\n",strlen(arr)); //5

    return 0;
}