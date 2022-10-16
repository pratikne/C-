/***STACK DS(ARRAY BASED)
 LIFO concept
 insertion and deletion can be performed at just one end i.e top
 APPLICATIONS:
 1)Insertion - O(1){O(n) for worst case when stack overflow case occurs}
 2)Deletion - O(1)
 3)Isempty
 4)Peek/Top - O(1)

 LOGIC.....int array of a particular size
 top field will store the index pushed....can be pushed till array size....STACK OVERFLOW will take place.
 whenever value to be inserted....top is incremented and element is assisgned at that index.
 for deletion....top index is decremented.
 If top is -1, stack is empty.

NOTE:::
 from linked list also, we can implement this.
 just note....insert and delete from the head node..as it will take constant time...otherwise traversal need to be done.
    i.e HEAD is act as TOP in STACK.

APPLICATIONS :
1) Balanced Parenthesis {}[]()
2) Reversing the list/array/string
3) Infix/Postfix/Prefix

for prefix evaluation......traverse from right to left
for postfix evaluation.....traverse from left to right

***/

#include<bits/stdc++.h>
using namespace std;

#define max_size 100
int A[max_size];
int top = -1;

bool isFull(){
    if(top == (max_size -1)){
        return true ;
    }
    return false;
}

void push(int x){
    if(top == (max_size -1)){
        cout<<"Error : Stack Overflow";
        return;
    }
    top++;
    A[top] = x;
}

void pop(){
    if(top == -1){
        cout<<"Error : Stack is already Empty";
    }
    top--;
}

int Top(){
    return A[top];
}

bool isEmpty(){
    if(top == -1) return true;
    return false;
}

void print(){
    cout<<"Stack elements : ";
    for(int i=0; i<=top; i++){
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

int main(){

    push(5);
    push(4);
    push(3);
    print();
    cout<<Top()<<endl;
    pop();
    print();
    cout<<isEmpty()<<endl;
    return 0;
}