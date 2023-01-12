/***SINGLE LINKED LIST DS***
1) Traversal -> O(n)
2) Insert at start/head -> O(1)
   Insert at position k -> O(k)
   Insert at end(n)     -> O(n)
3) Delete at start/head -> O(1)
   Delete at position k -> O(k)
   Delete at end(n)     -> O(n)
***/

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(){
        data = 0;
        next = NULL;
    }
    Node(int d, Node* p){
        data = d;
        next = p;
    }
};

Node *head; // global variable

int sizell()
{

    Node *ptr = head;
    int size = 0;
    while (ptr != NULL)
    {
        ptr = ptr->next;
        size++;
    }
    return size;
}

// Prepend at start
void InsertAtFirst(int x)
{
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;

    // If there is something in the list..so Head won't point to NULL
    if (head != NULL)
        new_node->next = head; // new_node's next will point to head  new_node->head

    head = new_node; // new_node is the new head
}

// Append at End
void InsertAtEnd(int x)
{
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;

    Node *ptr = head;
    while (ptr->next != NULL)
    { // ptr->new_node->NULL
        ptr = ptr->next;
    }
    ptr->next = new_node;
}

void InsertAtPosition(int pos, int x) //Index starts from 1 
{
    Node *new_node = new Node();
    new_node->data = x;
    new_node->next = NULL;

    if (pos <= 0)
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 1)
    { // 1 means first node which is head..so same like InsertatHead
        // InsertAtFirst(x);
        new_node->next = head;
        head = new_node;
        return;
    }

    if ((pos) > (sizell() + 1))
    { // plus 1..coz....we can insert element at NULL position as well
        cout << "Link overflow..cant insert" << endl;
        return;
    }

    Node *ptr = head;
    for (int i = 1; i < pos - 1; i++)
    {
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node; // new_node -> new_node1 -> next
}

void DeleteAtEnd()
{
    if (head == NULL)
        cout << "List is Empty" << endl;
    else if (head->next == NULL) // only 1 element
    {
        // free head and set it to NULL
        delete head;
        head = NULL;
    }
    else
    {
        // traverse to 2nd last element
        Node* temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        // delete last node now i.e new_node->next
        delete temp->next;
        temp->next = NULL;
    }
}

// delete at first included here
void DeleteAtPosition(int pos)
{
    Node *prev = head;
    if (pos <= 0 || pos > sizell())
    {
        cout << "Invalid position" << endl;
        return;
    }
    if (pos == 1)
    { // deleting head node or 1st node....so put next node after it as head
        head = head->next;
        delete prev;
        return;
    }

    for (int i = 1; i < pos - 1; i++)
    {
        prev = prev->next;
    }
    Node *curr = prev->next; // prev->curr->next
    prev->next = curr->next; // prev->next
    delete curr;
}

// Finds Maximum element in the list
void MaxElementInList()
{
    int maxn = INT_MIN;
    Node *temp = head;
    while (temp != NULL)
    {
        maxn = max(maxn, temp->data);
        temp = temp->next;
    }
    cout << "Maximum data in the list : " << maxn << endl;
}

// Finds Minimum element in the list
void MinElementInList()
{
    int minn = INT_MAX;
    Node *temp = head;
    while (temp != NULL)
    {
        minn = min(minn, temp->data);
        temp = temp->next;
    }
    cout << "Minimun data in the list : " << minn << endl;
}

bool searchKeyinLL(int key)
{
    Node *current = head;

    while (current != NULL)
    {
        if (current->data == key)
            return true;
        current = current->next;
    }
    return false;
}

// Sort LL in ascending order  O(N*N)
void SortSingleLL()
{
    bool sorted;
    Node *curr = head;
    Node *next = NULL;
    if (curr == NULL)
    {
        return;
    }
    else
    {
        while (curr != NULL)
        {
            sorted = true;
            next = curr->next;

            while (next != NULL)
            {
                if (curr->data > next->data)
                {
                    swap(curr->data, next->data);
                    sorted = false;
                }
                next = next->next;
            }
            curr = curr->next;

            if (sorted)
            {
                return;
            }
        }
    }
}

// Iterative reverse list (TC // O(n), SC // O(1))
void reverselist()
{                      
    Node* current = head; // 1 - 2 - 3 - 4 - NULL
    Node* previous = NULL;
    Node* forward = NULL;

    if(head == NULL || head->next == NULL){
        return; // do nothing as either the list is empty or just 1 node so no need of reversing
    }

    while (current != NULL)
    {
        forward = current->next;  // 1. save next node in forward
        current->next = previous; // 2. reverse the current link to prev
        previous = current;       // 3. move prev ahead
        current =  forward;       // 4. move curr ahead
    }

    head = previous;              // 5. End node is now the head
}


//-----------------------------------------------------------------------------------
// TC -> O(n)
// SC -> O(n)
void reversehelper(Node* &head, Node* &current, Node* &previous){
    if(current == NULL){
        head = previous;
        return;
    }
    Node* forward = current->next;
    reversehelper(head, forward, current);
    current->next = previous;
}

// Recursive reverse list
Node *recursivereverselist(Node *head)
{
    Node* current = head; // 1 - 2 - 3 - 4 - NULL
    Node* previous = NULL;

    if (head == NULL || head->next == NULL)
        return head;

    reversehelper(head, current, previous);
    return head;
}

// Smart Recursive linked list technique
Node *recursivereverselistNew(Node *head)
{
    // Base condition
    if (head == NULL || head->next == NULL)
        return head;

    // (1) -> [(2) -> (3) -> NULL]
    // head -> [                  ]
    // smallNode is pointing to last Node (Reverse links head node)
    // Just focus on your head 
    // just need to point head->next->next to itself
    // and then point its own next to NULL

    Node* smallNode = recursivereverselistNew(head->next);

    head->next->next = head; // as head->next is pointing to smallnode
    head->next = NULL;

    return smallNode;
}



//Reverse first k nodes

Node* kReverse(Node* head, int k){
    if(head == NULL || head->next == NULL){
        return head; //No need to reverse
    }

    // step 1: reverse first k nodes through iterative method
    Node* current = head; // 1 - 2 - 3 - 4 - NULL
    Node* previous = NULL;
    Node* forward = NULL;
    int count = 0;

    while (current != NULL && count < k) 
    {
        forward = current->next;  // 1. save next node in forward
        current->next = previous; // 2. reverse the current link to prev
        previous = current;       // 3. move prev ahead
        current =  forward;       // 4. move curr ahead
        count++;
    }

    // step 2: Recussion dekh lenga khud ab
    if(forward!=NULL){
        head->next = kReverse(forward, k);
    }

    return previous;
}
//-----------------------------------------------------------------------------------


// To find middlemost element in a linked list in single loop is to use double pointer concept wherein one pointer will go with double the speed of second pointer

void printlist()
{ // O(n)
    Node *temp = head;
    int size = 0;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
        size++;
    }
    cout << "NULL : Size is " << size << endl;
}

/***for this, declare head locally within main....
void printreverse(Node* ptr){
    if(ptr == NULL)
        return;
    printreverse(ptr->next);
    cout<<ptr->data<<endl;
}
***/

int main()
{
    Node *head = NULL;
    cout << "How many numbers : ";
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the value : ";
        cin >> x;
        InsertAtFirst(x);
    }
    printlist();             // let say 3 2 1
    InsertAtPosition(1, 5);  // 5 3 2 1
    InsertAtPosition(3, 10); // 5 3 10 2 1
    // InsertAtPosition(10,20);
    InsertAtEnd(30); // 5 3 10 2 1 30
    InsertAtEnd(59); // 5 3 10 2 1 30 59
    printlist();
    InsertAtPosition(9, 20); // will insert at 9th pos (No 0 index)
    InsertAtPosition(8, 20); // will insert at 8th pos (No 0 index)
    InsertAtPosition(7, 20); // will insert at 7th pos (No 0 index)
    printlist();
    DeleteAtPosition(5);  // deleted element at 5th value
    DeleteAtPosition(10); // Invalid position as out of bound
    DeleteAtPosition(1);  // deleted first node
    printlist();
    int size = sizell();        // will give size of list
    DeleteAtPosition(sizell()); // deletes at the end
    printlist();
    // head = reverselist();
    reverselist();
    printlist();
    head = recursivereverselist(head);
    printlist();
    // printreverse(head);

    MinElementInList();
    MaxElementInList();
    SortSingleLL();
    cout << "Sorted Data ::: ";
    printlist();
    
    bool isthere = searchKeyinLL(20);
    if(isthere){
        cout << "Key 20 present" << endl; 
    }
    else{
        cout << "Key 20 not present" << endl; 
    }

    return 0;
}