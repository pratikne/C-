#include<bits/stdc++.h>

#define SIZE 5
using namespace std;


class QueueImp{
    int front ;
    int rear ;
    int A[SIZE];
public:

    QueueImp(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){ //O(1)
        if(front == -1 && rear == -1){
            cout<<"Queue is Empty"<<endl;
            return true;
        }
        else
            return false;
    }

    bool isFull(){ //O(1)
        if((rear+1) % SIZE == front) {
            cout<<"Queue is Full"<<endl;
            return true;
        }
        else    
            return false;
    }
    
    void push(int x){ //O(1)
        if(isFull()) //concept of circular array..checking whether queue is Full
            return;
        else if(isEmpty()){
            front = 0;
            rear = 0;
            A[rear] = x;
        }
        else{
            rear = (rear+1) % SIZE ;
            A[rear] = x;
        }
    }

    void pop(){  //O(1)
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return;
        }
        else if(front == rear){ //only 1 element
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % SIZE ;
        }
    }

    int frontTop(){ //O(1)
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            return A[front];
        }
    }
    
    int back(){ //O(1)
        if(isEmpty()){
            cout<<"Queue is Empty"<<endl;
            return -1;
        }
        else{
            return A[rear];
        }
    }

};

int main(){

    QueueImp q;
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    cout<< q.frontTop() <<endl;
    cout<< q.back() <<endl;
    q.pop();
    cout<< q.frontTop() <<endl;
    cout<< q.back() <<endl;
    cout<< q.isEmpty() <<endl;
    cout<< q.isFull() <<endl;

    return 0;
}