/***Heapify
By DEF :  MAXHEAP implemented in STL (priority queue)
for MINHEAP : use greater<int> as srd arg

push :O(logN)
pop :O(logN)
top :O(1)
size :O(1)

internally uses make_heap, push_heap, pop_heap functions

Priority queues are a type of container adapters, specifically designed such that the first element of the queue is either the greatest or the smallest of all elements in the queue and elements are in nonincreasing order (hence we can see that each element of the queue has a priority {fixed order}). However in C++ STL, by default, the top element is always the greatest element. We can also change it to the smallest element at the top. Priority queues are built on the top to the max heap and uses array or vector as an internal structure.

**/


#include<bits/stdc++.h>
#include<queue>

using namespace std;

int main(){
    //vector<int> heap = {3,2,1,5,6}; //correct but not in C++98

    //Below steps to initialize vector with the help of array
    int arr[] = {3,2,1,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    vector<int> heap(arr,arr+n);

    //below defined in algorithm header
    //make_heap(heap.begin(),heap.end()); //creates max-heap by default
    //front element is the biggest -> heap.front()
    make_heap(heap.begin(),heap.end(),greater<int>() ); //creates min-heap(parent node smaller than child node)
    //here, heap.front() returns smallest
    //To insert new value
    heap.push_back(9);
    push_heap(heap.begin(),heap.end(), greater<int>() ); //NOTE : before pushback...heap should be created

    for(int i = 0; i < heap.size(); i++){
        cout<<heap[i]<<" ";
    }cout<<endl;

    pop_heap(heap.begin(),heap.end(), greater<int>() ); //it will remove first element from heap but not from vector
    heap.pop_back();

    for(int i = 0; i < heap.size(); i++){
    cout<<heap[i]<<" ";
    }cout<<endl;

    sort_heap(heap.begin(),heap.end(), greater<int>() );
    for(int i = 0; i < heap.size(); i++){
    cout<<heap[i]<<" ";
    }cout<<endl;
    //To check whether a structure is heap
/**
    bool ans = is_heap(heap.begin(),heap.end()); 
    if(ans == true) 
        cout<<"HEAP YES";
    else
        cout<<"HEAP NO";
**/

/**MAX HEAP with priority queue**/

    priority_queue<int> gquiz; // creates MAX-HEAP
    gquiz.push(10);
    gquiz.push(30);
    gquiz.push(20);
    cout << "\ngquiz.top() : " << gquiz.top();
  
    cout << "\ngquiz.pop() : ";
    gquiz.pop();

    priority_queue<int, vector<int> > pq; // creates MAX-HEAP

    pq.push(3);
    pq.push(2);
    pq.push(1);
    pq.push(5);
    pq.push(6);
    cout<<"SIZE OF MAXHEAP : " << pq.size() << endl; //5

    cout<<pq.top()<<endl; //Gives topmost value or greater of all as it is maxheap

    pq.pop();

    cout<<pq.top()<<endl; //Gives topmost value or greater of all as it is maxheap

    while(!pq.empty()){
        cout<< pq.top() << '\t';
        pq.pop();
    }cout<<endl;



/**MIN hEAP with priority queue**/ //IMP
    priority_queue<int, vector<int>, greater<int> > pqm;

    pqm.push(2);
    pqm.push(3);
    pqm.push(1);
    
    cout<<pqm.top()<<endl; //Gives topmost value or smallest of all as it is minheap

    pqm.pop();
    cout<<pqm.top()<<endl; //Gives topmost value or smallest of all as it is minheap

    return 0;
    /**
     * APPLICATIONS
     * 
     * 1. OS for load balancing
     * 2. Interrupt handling
     * 3. Heap sort
     * 4. AI 
     * 
     */
}

