#include<bits/stdc++.h>

#define SIZE 10
using namespace std;


class StackImp{
    int top ;
    int A[SIZE];
public:

    StackImp(){
        top = -1;
    }

    bool isEmpty(){ //O(1)
        if(top == -1){
            return true;
        }
        else
            return false;
    }

    bool isFull(){ //O(1)
        if(top == SIZE-1) {
            return true;
        }
        else    
            return false;
    }
    
    void push(int x){ //O(1)
        if(isFull()){ 
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else{
            top++ ;
            A[top] = x;
        }
    }

    void pop(){  //O(1)
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        else{
            top-- ;
        }
    }

    int Top(){ //O(1)
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            return A[top];
        }
    }

    void Print(){
        for(int i=0; i<=top; i++)
            cout<<A[i]<< " ";
        cout<<endl;
    }

};

int main(){

    StackImp q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.Print();
    cout<< q.Top() <<endl;
    q.pop();
    q.Print();
    cout<< q.Top() <<endl;
    cout<< q.isEmpty() <<endl;
    cout<< q.isFull() <<endl;

    return 0;
}