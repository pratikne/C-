#include<bits/stdc++.h>
using namespace std;

class QueueImp{
    stack<int> s1;
    stack<int> s2;
public:
    void push(int x){
        s1.push(x);
    }

    void pop(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        //int topV = s2.top();
        s2.pop();
        //return topV;
    }

    int top(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        int topV = s2.top();
        return topV;
    }

    bool empty(){
        if(s1.empty() && s2.empty()){
            cout<<"Queue is Empty"<<endl;
            return true;
        }
        else
            return false;
    }

};

int main(){

    QueueImp q;
    q.push(2);
    q.push(5);
    q.push(7);
    cout<< q.top() <<endl;
    q.pop();
    cout<< q.top() <<endl;
    cout<< q.empty() <<endl;

    return 0;
}