/**************DOUBLE LINKED LINEAR LIST IMPLEMENTATION***************/
#include <bits/stdc++.h>
#include <iostream>
#include <list>   //this is must for implementing list
#include<iterator>
using namespace std;

void print(list<int> &li){
    list<int> :: iterator g = li.begin();
    cout << "NULL<->";
    while(g != li.end()){
        cout<<*g<<"<->";
        g++;
    }
    cout<<"NULL"<<endl;
}

int main(){

    int arr[] = {10,20,30};
    list <int> mylist(arr,arr + 3); //copies 3 array elemnts from start in list 
    list <int> :: iterator it, it2 ;

    /**INSERTING and DELETING elements in a list from front/back**/
    mylist.push_front(11);
    print(mylist); 

    mylist.push_back(15);
    print(mylist);

    mylist.push_front(12);
    print(mylist); 

    mylist.push_back(75);
    print(mylist);

    mylist.push_front(11);
    print(mylist); 

    mylist.push_back(15);
    print(mylist);

    mylist.pop_back();
    print(mylist); 

    mylist.pop_front();
    print(mylist);

    list<int> list2(3,10); //3 values with 10 stored in them
    print(list2);

    /**SWAPPING between 2 list**/
    cout<<"After swapping"<<endl;
    mylist.swap(list2);
    print(mylist);
    print(list2);

    /**REVERSING in LIST**/
    list2.reverse();
    print(list2);

    /**SORTING***/
    //sort(list2.begin(),list2.end()); //dont work in list..works in continuous memory like array and vectors
    list2.sort(); //bydefault in asc order
    print(list2);
    list2.sort(greater<int>());   //sorts in desc order
    print(list2);

/**other logic for reverse traversing list**/
    list<int> :: reverse_iterator ir;
    ir = list2.rbegin();
    while(ir != list2.rend()){
        cout<<*ir<<" ";
        ir++;
    }
    cout<<endl;

    /**checking if list is empty or not**/
    if(list2.empty()){
        cout<<"List empty"<<endl;
    }
    else{
        cout<<"List not empty"<<endl;
    }

    cout<<"Size of list2 is "<<list2.size()<<endl;
    cout<<"Max Size of list2 is "<<list2.max_size()<<endl;
    list2.resize(5);
    cout<<"Size of list2 is "<<list2.size()<<endl;
    print(list2);

    /**Accessing first and last element**/
    cout<<"First element is "<<list2.front()<<endl;
    cout<<"Last element is "<<list2.back()<<endl;

    /**Inserting within a list**/
    it = list2.begin();
    list2.insert(it,3,10);  //insert 3 10's from the position fixed at it.
    print(list2);   

    cout<<"Value at that iterator now is "<<*it<<endl;  //that means..iterator is fixed until moved
    it=list2.begin(); //pointing to 0th index...1st element
    it++;             //now point to 1st index...2nd element
    list2.insert(it,25); //insert 25 at that position pointed by it
    print(list2);

    it=list2.begin(); //pointing to 0th index...1st element
    advance(it,5);    //shifts 5 positions from it in RHS
    cout<<"Value at that iterator now is "<<*it<<endl;

    vector<int> v1(3,15);
    list2.insert(list2.begin(),v1.begin(),v1.end()); // 15 15 15
    print(list2);

    /**removing duplicate entries in sorted list...doesnt work for unsorted list**/
    list2.sort();
    list2.unique();
    print(list2);

    /***Erasing elements in list**/
    it=list2.begin(); //pointing to 0th index...1st element
    advance(it,5);    //shifts 5 positions from it in RHS
    cout<<"Value at that iterator now is "<<*it<<endl;
    list2.erase(it);   ///removes element at that position IMP*
    print(list2);

    it= list2.begin();
    cout<<"Value at that iterator now is "<<*it<<endl;
    it2=list2.begin();
    advance(it2,4);
    cout<<"Value at that iterator now is "<<*it2<<endl;
    list2.erase(it,it2);   //removes all element between it and it2 such as [it,it2)
    /**NOTE
     * Erase for iterators
     * Remove for constant values
    */
    print(list2);

    /**Remove specific elenmet **/
    list2.push_front(75);
    print(list2);
    list2.remove(75);  ///removes all occurence of that value in the list..if not present...np
    print(list2);

    list2.clear();
    mylist.clear();
    print(list2);
    print(mylist);
    return 0;
}