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
            cout<<"Stack is Empty"<<endl;
            return;
        }
        else{
            top-- ;
        }
    }

    int Top(){ //O(1)
        if(isEmpty()){
            cout<<"Stack is Empty"<<endl;
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
/**
 * Applications of Stack Data Structure
Although stack is a simple data structure to implement, it is very powerful. The most common uses of a stack are:

1. To reverse a word - Put all the letters in a stack and pop them out. Because of the LIFO order of stack, you will get the letters in reverse order.
2. In compilers - Compilers use the stack to calculate the value of expressions like 2 + 4 / 5 * (7 - 9) by converting the expression to prefix or postfix form.
3. In browsers - The back button in a browser saves all the URLs you have visited previously in a stack. Each time you visit a new page, it is added on top of the stack. When you press the back button, the current URL is removed from the stack, and the previous URL is accessed.
 * 
 */