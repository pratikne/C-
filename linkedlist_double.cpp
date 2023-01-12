// https://www.programiz.com/dsa/doubly-linked-list

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(){
        data = 0;
        next = NULL;
        prev = NULL;
        //cout << "New Node created" << endl;
    }

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete this->next;
            this->next = NULL;
        }
        cout << "Memory freed for Node having data " << value << endl;
    }
};

// Node *head; // global variable

// void InsertAtFirst(int x)
// {
//     Node* temp = new Node();
//     temp->data = x;
//     temp->next = NULL;
//     temp->prev = NULL;

//     // If there is something in the list..so Head won't point to NULL
//     if (head != NULL)
//         temp->next = head; // temp's next will point to head  temp->head

//     head = temp; // temp is the new head
// }

// void InsertAtEnd(int x)
// {
//     if(head == NULL){
//         InsertAtFirst(x);
//     }

//     Node* temp = new Node();
//     temp->data = x;
//     temp->next = NULL;
//     temp->prev = NULL;

//     Node* ptr = head;
//     while (ptr->next != NULL)
//     { // ptr->temp->NULL
//         ptr = ptr->next;
//     }
//     ptr->next = temp;
//     temp->prev = ptr;
// }

// int sizell()
// {

//     Node *ptr = head;
//     int size = 0;
//     while (ptr != NULL)
//     {
//         ptr = ptr->next;
//         size++;
//     }
//     return size;
// }

// insert node at the front
void insertFront(Node *&head, int data)
{
    // allocate memory for newNode
    Node *newNode = new Node;

    // assign data to newNode
    newNode->data = data;

    // make newNode as a head
    newNode->next = (head);

    // assign null to prev
    newNode->prev = NULL;

    // previous of head (now head is the second node) is newNode
    if ((head) != NULL)
        (head)->prev = newNode;

    // head points to newNode
    (head) = newNode;
}

// insert a node after a specific node
void insertAfter(Node *&prev_node, int data)
{
    // check if previous node is null
    if (prev_node == NULL)
    {
        cout << "previous node cannot be null";
        return;
    }

    // allocate memory for newNode
    Node *newNode = new Node;

    // assign data to newNode
    newNode->data = data;

    // set next of newNode to next of prev node
    newNode->next = prev_node->next;

    // set next of prev node to newNode
    prev_node->next = newNode;

    // set prev of newNode to the previous node
    newNode->prev = prev_node;

    // set prev of newNode's next to newNode
    if (newNode->next != NULL)
        newNode->next->prev = newNode;
}

// insert a newNode at the end of the list
void insertEnd(Node *&head, int data)
{
    // allocate memory for node
    Node *newNode = new Node;

    // assign data to newNode
    newNode->data = data;

    // assign null to next of newNode
    newNode->next = NULL;

    // store the head node temporarily (for later use)
    Node *temp = head;

    // if the linked list is empty, make the newNode as head node
    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    // if the linked list is not empty, traverse to the end of the linked list
    while (temp->next != NULL)
        temp = temp->next;

    // now, the last node of the linked list is temp

    // assign next of the last node (temp) to newNode
    temp->next = newNode;

    // assign prev of newNode to temp
    newNode->prev = temp;
}

// delete a node from the doubly linked list
void deleteNode(Node *&head, Node *del_node)
{
    // if head or del is null, deletion is not possible
    if (head == NULL || del_node == NULL)
        return;

    // if del_node is the head node, point the head pointer to the next of del_node
    if (head == del_node)
        head = del_node->next;

    // if del_node is not at the last node, point the prev of node next to del_node to the previous of del_node
    if (del_node->next != NULL)
        del_node->next->prev = del_node->prev;

    // if del_node is not the first node, point the next of the previous node to the next node of del_node
    if (del_node->prev != NULL)
        del_node->prev->next = del_node->next;

    // free the memory of del_node
    del_node->next = NULL;
    delete del_node;
}

// print the doubly linked list
void displayList(Node *node)
{
    // Node* last;

    while (node != NULL)
    {
        cout << node->data << "->";
        // last = node;
        node = node->next;
    }
    if (node == NULL)
        cout << "NULL\n";
}

void reverseDLL(Node* &head){

    Node* temp = NULL;
    Node* current = head;

    while(current != NULL){
        // Swap next and prev of current
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;  //IMP - It will move forward
    }

    // if temp is NULL, that means either 0 node or just 1 node..so no need to change head
    if(temp != NULL){
        head = temp->prev;
    }
}

int main()
{
    // initialize an empty node
    Node *head = NULL;

    insertEnd(head, 5);
    insertFront(head, 1);
    insertFront(head, 6);
    insertEnd(head, 9); // 6 1 5 9
    displayList(head);

    // insert 11 after head
    insertAfter(head, 11); // 6 11 1 5 9

    // insert 15 after the seond node
    insertAfter(head->next, 15); // 6 11 15 1 5 9

    displayList(head);

    // delete the last node
    deleteNode(head, head->next->next->next->next); // 6 11 15 1 5 9

    displayList(head);

    reverseDLL(head);
    displayList(head);

}