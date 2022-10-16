/**************PAIR IMPLEMENTATION***************/
#include <bits/stdc++.h>
#include <iostream>
#include <utility>   //this is must for implementing pairs
using namespace std;

int main(){

    pair<int, int> pair1;
    pair1.first = 100;
    pair1.second = 200;
    cout<<pair1.first<<" "<<pair1.second<<endl;    //{100,200}

    pair<int, char> pair2;   //datatypes can be same or diff
    pair2.first = 100;
    pair2.second = 'P';
    
    /**NOTE : If we store nothing..just declare it....default values are stored for that datatype
    i.e for int, float, long, double....0
    for string and char....NULL**/

    //Accessing elements stored in pair
    cout<<pair2.first<<" "<<pair2.second<<endl;    //{100,G}

    //Different ways to initialize pairs
    pair<int, char> P1 = make_pair(2,'S');     //using make_pair function;
    pair<int, char> P2(10,'N');
    pair<int, char> P3(P2);    //P2 gets assigned to P3 
    pair<string, double> P4("Pratik Negi", 99.99);
    cout<<P1.first<<" "<<P1.second<<endl; 
    cout<<P2.first<<" "<<P2.second<<endl; 
    cout<<P3.first<<" "<<P3.second<<endl;
    P3.second = 'O'; 
    /**cout<<"After swap :"<<endl;
    P1.swap(P2);  //swaps pair contents
    cout<<P1.first<<" "<<P1.second<<endl; 
    cout<<P2.first<<" "<<P2.second<<endl; **/ //Not in this C++ release..will work in C++ 11

    /** We can  also use logical operatir such as =,>=,<=,!=,==
     * it first checks for first element and if same..goes for second element 
     * Retirns bool value...True - 1
     * False - 0**/

    cout<<(P1 == P2)<<endl;  //0
    cout<<(P3 == P2)<<endl; //1
    cout<<(P1 > P2)<<endl; //0
    cout<<(P1 < P2)<<endl; //1
    cout<<(P3 >= P2)<<endl; //1

  /**  int a;
    char b;
    tie(a, b) = P1;
    cout<<a<< " "<< b;   //2 S
    **/

    pair<int, pair<string, char> > P5(200, {"Pratik", 'P'} );   //Pair within pair
    pair<int, pair<string, pair<int,char> > > P7(200, {"Pratik", {10,'P'} } );
    pair<int, pair<string, pair<int,char> > > P8 = make_pair(200, make_pair("Pratik", make_pair(10,'P') ) );
    //pair<int, pair<string, char> > P5 = {200, {"Pratik",'P'}};   //this style of Pair within pair..not working here
    cout<< P5.first << " " << P5.second.first << " " << P5.second.second << endl;
    cout<< P7.first << " " << P7.second.first << " " << P7.second.second.first << " " << P7.second.second.second << endl;
    cout<< P8.first << " " << P8.second.first << " " << P8.second.second.first << " " << P8.second.second.second << endl;

    pair<int, int> arr[] = { {1,2}, {3,4} };   //Array of pair
    pair<int, string> arr2[] = { {5,"Pratik"}, {3,"Ritik"} };   //Array of pair

    //No size function in pairs
    cout<< sizeof(arr)/sizeof(arr[0]) <<endl;  ///use this for getting arr size
    int size = sizeof(arr2)/sizeof(arr2[0]);

    sort(arr2,arr2 + size);  //function of algorithm header which sorts acc to first element

    for(int i=0; i < size; i++){
        cout<<arr2[i].first <<" " << arr2[i].second <<endl;
    }
    cout<<arr[1].second;

    return 0;
}