// Max-Heap data structure in C++
// Heap is complete binary Tree that comes with Heap order property

//Complete Bonary Tree
//    All levels filled except possibly lowest one
//    All nodes tend towards left
/**
 * i is the index of node in array
 * 
 * 
 * //1 index based
 * left child = (2 * i)th index
 * right child = (2 * i + 1)th index
 * parent = (index of child / 2)th index
 * 
 * //0 index based
 * left child = (2 * i) + 1th index
 * right child = (2 * i + 2)th index
 * parent = (index of child - 1/ 2)th index
 * 
 */

#include <iostream>
#include <vector>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}


// Creates max-heap
void heapify(vector<int> &hT, int size, int i)
{
    // int size = hT.size();
    int largest = i; //Parent index
    int l = 2 * i + 1; // Left child, we are using from 0th index
    int r = 2 * i + 2; // Right child, we are using from 0th index
    //check if left child is bigger
    if (l < size && hT[l] > hT[largest])
        largest = l;
    //check if right child is bigger
    if (r < size && hT[r] > hT[largest])
        largest = r;

    if (largest != i)
    {
        swap(&hT[i], &hT[largest]);
        heapify(hT, size, largest);
    }
}

void insert(vector<int> &hT, int newNum)
{
    int size = hT.size();
    if (size == 0)
    {
        hT.push_back(newNum);
    }
    else
    {
        hT.push_back(newNum);
        //now check for parent nodes
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(hT, size, i);
        }
    }
}

void deleteNode(vector<int> &hT, int num)
{
    int size = hT.size();
    int i;
    for (i = 0; i < size; i++)
    {
        if (num == hT[i])
            break;
    }
    swap(&hT[i], &hT[size - 1]); //put the value at last index which you want to delete

    hT.pop_back(); //removes element from the end
    // heapify the structure again
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        heapify(hT, size, i);
    }
}

void SortHeap(vector<int> &hT){ //nlogn
    int size = hT.size();

    while(size > 0){
        swap(hT[size-1], hT[0]);
        size--;
        heapify(hT, size, 0);
    }
}


void printArray(vector<int> &hT)
{
    for (int i = 0; i < hT.size(); ++i)
        cout << hT[i] << " ";
    cout << "\n";
}

int main()
{
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    cout << "Max-Heap array: ";
    printArray(heapTree);

    deleteNode(heapTree, 4);

    cout << "After deleting an element: ";
    printArray(heapTree);

    insert(heapTree, 7);
    cout << "Max-Heap array: ";
    printArray(heapTree);

    SortHeap(heapTree);
    printArray(heapTree);
}

/**
Heap Data Structure Applications
Heap is used while implementing a priority queue.
Dijkstra's Algorithm
Heap Sort**/