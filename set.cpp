/***************SET IMPLEMENTATION*****************/
//Associative container wherein each element is unique
#include <iostream>
#include <set>  //Must be present for ordered(asc) non repeating element
#include<algorithm>
using namespace std;

int main(){

    set<int> myset;    //This will initiate set which will store elements in asc order(default)
    //set<int, greater<int> > myset;    //This will initiate set which will store elements in desc order
    set<int> :: iterator it;


    myset.insert(20); //{20}
    myset.insert(50); //{20,50}
    myset.insert(90); //{20,50,90}..note..order might change 
    myset.insert(50); //{20,50,90}.....50 wont be inserted again..as its already there.

    int count = myset.size();
    cout<<"Size is "<<count<<endl;

    //sort(myset.begin(),myset.end());  //this doesnt work...as set are not continuous

    for (it = myset.begin(); it != myset.end(); it++)
    {
        cout<<*(it)<< " ";
    }
    cout<<endl;

    set<int> myset2(myset.begin(),myset.end());  //copies set1 to set2

    for (it = myset2.begin(); it != myset2.end(); it++)
    {
        cout<<*(it)<< " ";
    }
    cout<<endl;

    //No front, back, sort and reverse

    ///myset2.erase(50);    20 90
    //myset2.erase(myset2.begin(),myset2.end());   // Nothing..all erased

    //it = myset2.begin()++;
    //myset2.erase(myset2.find(50)); //...finds 50 and points it over there...and then erase removes that it value.  
    myset2.erase(myset2.begin(),myset2.find(50)); //erase[start_ite, end_iter)...[start,end)...end is exclusive
    for (it = myset2.begin(); it != myset2.end(); it++)
    {
        cout<<*(it)<< " ";
    }
    cout<<endl;
    cout<<*myset.begin()<<endl;          //prints first element in set
    cout<<*myset.rbegin()<<endl;         //prints last element in set
    cout<<*myset.lower_bound(40)<<endl;  //find lower bound of that value passed....lower bound is value equal to or just greater than that if match not found
    cout<<*myset.upper_bound(50)<<endl;  //finds upper bound....greater value than value passed

    return 0;
}