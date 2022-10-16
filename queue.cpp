/**************QUEUE IMPLEMENTATION*****************/
/***
No iterator concept here same as stack..Just it is based on FIFO
***/
#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

int main(){

    queue<int> myqueue;

    cout<<"Queue size : "<<myqueue.size()<<endl;

    myqueue.push(10);
    myqueue.push(20);
    myqueue.push(30);
    myqueue.push(20);

    cout<<"Queue size : "<<myqueue.size()<<endl;
    cout<<"Queue first ele : "<<myqueue.front()<<endl;  //element which is inserted first..so it will be in front
    cout<<"Queue last ele : "<<myqueue.back()<<endl;  //last to be pushed
    //cout<<"Top last ele : "<<myqueue.top()<<endl;   //No top function here in queue

    cout<<myqueue.empty()<<endl; //returns bool 0/1

    while(!myqueue.empty()){
        cout<<myqueue.front()<< " ";
        myqueue.pop();   //pops first element pushed..i.e from front
    }
    cout<<endl;

    cout<<"Queue size : "<<myqueue.size()<<endl;    //0
    cout<<"Queue first ele : "<<myqueue.front()<<endl;   //0
    cout<<"Queue last ele : "<<myqueue.back()<<endl;  //stores last element
    return 0;
}