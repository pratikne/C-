/************STACK************/
/**Based on LIFO
Element added is always at top and removal will be done from top i.e push and pop operation.
also, we can view just top element.
**/

//#include<bits/stdc++.h>
#include<iostream>
#include<stack>
#include<iterator>
using namespace std;

int main()
{
    stack<int> st;   //declaring stack of int type
    stack<int> st2;
    //stack<int> :: iterator it;   //we dont have iterator in stack

    st.push(10);
    st.push(20);
    st.push(30);

    st2.push(70);
    st2.push(80);

    st.top() = 50;     //top element is changeable...30 to 50
    st.top() += 50;    //100

    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    cout<<st.empty()<<endl;  //returns 0/1......0 if false....1 if true
/**
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    **/

    //st2.swap(st);   Noy yet ..its in latest c++

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;

    while(!st2.empty()){
        cout<<st2.top()<<" ";
        st2.pop();
    }
    cout<<endl;
    return 0;
}