/***SINGLE LINKED LIST DS***
1) Traversal -> O(n)
2) Insert at start/head -> O(1)
   Insert at position n -> O(n)
3) Delete at start/head -> O(1)
   Delete at position n -> O(n)
***/
#include<bits/stdc++.h>
using namespace std;

class Node{
 public:
    int data;
    Node* next;
};

Node* head; //global variable 

int sizell(){
    
    Node* ptr = head;
    int size = 0;
    while(ptr != NULL){
        ptr = ptr->next;
        size++;
    }
    return size;
}


void InsertAtFirst(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    if(head != NULL)
        temp->next = head; //temp's next will point to head  temp->head
    head = temp;    //temp is the new head    
} 

void InsertAtPosition(int pos, int x){
    Node* temp1 = new Node();
    temp1->data = x;
    temp1->next = NULL;

    if(pos<=0){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos == 1){   // 1 means first node which is head..so same like InsertatHead
        temp1->next = head;
        head = temp1;
        return;
    }

    if((pos) > (sizell() + 1) ){   //plus 1..coz....we can insert element at NULL position as well
        cout<<"Link overflow..cant insert"<<endl;
        return;
    }
    
    Node* temp = head;
    for(int i = 1; i < pos-1; i++){
        temp = temp->next;
    }
    temp1->next = temp->next;
    temp->next = temp1;  //temp -> temp1 -> next
}

void InsertAtEnd(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;
    Node* ptr = head;
    while(ptr->next != NULL){  //ptr->temp->NULL
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void DeleteAtEnd(){
    if(head == NULL)
        cout << "List is Empty" << endl;
    else if (head->next == NULL) //only 1 element
    {
        //free head and set it to NULL
        delete head;
        head = NULL;
    }
    else{
        //traverse to 2nd last element
        Node* temp = head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }

        //delete last node now i.e temp->next
        delete temp->next;
        temp->next = NULL;
    }
}

void DeleteAtPosition(int pos){
    Node* prev = head;
    if(pos <= 0 || pos > sizell()){
        cout<<"Invalid position"<<endl;
        return;
    }
    if(pos == 1){ //deleting head node or 1st node....so put next node after it as head
        head = prev->next;
        delete prev;
        return;
    }

    for(int i=1; i < pos-1; i++){
        prev = prev->next;
    }
    Node* curr = prev->next;   //prev->curr->next
    prev->next = curr->next;   //prev->next
    delete curr;               
}

//Node* reverselist(){
void reverselist(){
    Node* curr = head;   // 1 - 2 - 3 - 4 - NULL
    Node* prev;
    Node* next;
    prev = NULL;

    while(curr != NULL){
        next = curr->next; //save next node
        curr->next = prev; //reverse the curr link
        prev = curr; //move prev ahead
        curr = next; //move curr ahead
    }
    head = prev; //End node is now the head
    //return head;
}

Node* recursivereverselist(Node* &head){

    if(head = NULL || head->next = NULL)
        return head;

    Node* newhead = recursivereverselist(head->next);
    head->next->next = head
    head->next = NULL;
    return newhead;
}

//To find middlemost element in a linked list in single loop is to use double pointer concept wherein one pointer will go with double the speed of second pointer
void printlist(){
    Node* temp = head;
    int size = 0;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
        size++;
    }
    cout<<"Size is "<<size<<endl;
}

/***for this, declare head locally within main....
void printreverse(Node* ptr){
    if(ptr == NULL) 
        return;
    printreverse(ptr->next);
    cout<<ptr->data<<endl;
}
***/

int main(){
    Node* head = NULL;
    cout<<"How many numbers : ";
    int n,x;
    cin>>n;
    for(int i=0; i<n; i++){
        cout<<"Enter the value : ";
        cin>>x;
        InsertAtFirst(x);
    } 
    printlist(); //let say 3 2 1 
    InsertAtPosition(1,5);  // 5 3 2 1
    InsertAtPosition(3,10); // 5 3 10 2 1 
    //InsertAtPosition(10,20);
    InsertAtEnd(30); // 5 3 10 2 1 30
    InsertAtEnd(59); // 5 3 10 2 1 30 59
    printlist();
    InsertAtPosition(9,20); //wont insert.....link overflow
    InsertAtPosition(8,20); //will insert at the end
    InsertAtPosition(7,20); //will insert at 7th index 
    printlist();
    DeleteAtPosition(5); //deleted element at 5th value
    DeleteAtPosition(10); //Invalid position as out of bound
    DeleteAtPosition(1); //deleted first node
    printlist();
    int size = sizell(); //will give size of list
    DeleteAtPosition(sizell()); //deletes at the end
    printlist();
    //head = reverselist();
    reverselist();
    printlist();
    Node* newhead = recursivereverselist(head);
    printlist();
    //printreverse(head);
    return 0;
}