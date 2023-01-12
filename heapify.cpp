// Heap is complete binary Tree that comes with Heap order property

// Complete Bonary Tree
//     All levels filled except possibly lowest one
//     All nodes tend towards left
/**
 * i is the index of node in array
 *
 * left child = (2 * i)th index
 * right child = (2 * i + 1)th index
 * parent = (index of child / 2)th index
 *
 * leaf nodes lie between (n/2 + 1)th index till nth index
 * where n is the total nodes
 *
 * leaf nodes are heap by itself so no need to process it in heapify as they are in their correct position
 *
 */

#include <iostream>
#define SIZE 10
using namespace std;

class Heap
{
private:
    int arr[SIZE];
    int size;

public:
    Heap()
    {
        arr[SIZE] = {0};
        size = 0;
    }

    void Insert(int data)
    {
        size = size + 1;
        int index = size;
        arr[index] = data;

        while (index > 1)
        {
            int parent_ind = index / 2;

            if (arr[parent_ind] < arr[index])
            {
                swap(arr[parent_ind], arr[index]);
                index = parent_ind;
            }
            else
            {
                return;
            }
        }
    }

    void Delete()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
        }

        // Put last element in 1st index i.e root of tree
        arr[1] = arr[size];
        size = size - 1;

        int ind = 1;
        while (ind < size)
        {
            int left_ind = 2 * ind;
            int right_ind = 2 * ind + 1;

            if (left_ind < size && arr[left_ind] > arr[ind])
            {
                swap(arr[left_ind], arr[ind]);
                ind = left_ind;
            }
            else if (right_ind < size && arr[right_ind] > arr[ind])
            {
                swap(arr[right_ind], arr[ind]);
                ind = right_ind;
            }
            else
            {
                return;
            }
        }
    }

    

    void Print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int n , int i) //logN
    {
        int largest = i;
        int l = 2 * i ; 
        int r = 2 * i + 1;

        if (l <= n &&  arr[largest] < arr[l])
            largest = l;
        if (r <= n &&  arr[largest] < arr[r])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }


void SortHeap(int arr[], int size){ //nlogn

    while(size > 1){
        swap(arr[size], arr[1]);
        size--;
        heapify(arr,size,1);
    }
}

int main()
{
    Heap h1;
    h1.Insert(10);
    h1.Insert(20);
    h1.Insert(30);
    h1.Insert(40);
    h1.Insert(50);

    h1.Print();

    //            50
    //        40      20
    //      10  30

    h1.Delete();
    h1.Print();

    h1.Delete();
    h1.Print();

    int arra[] = {-1,50,51,52,53,54,55};
    int n = 6;
    for(int i = n/2 ; i>0; i--){
        heapify(arra, n, i);
    }

    cout << "Printing the array :\n";
    for(int i=1; i<=n; i++){
        cout << arra[i] << " ";
    }
    cout << endl;

    SortHeap(arra, n);
    cout << "Printing the array :\n";
    for(int i=1; i<=n; i++){
        cout << arra[i] << " ";
    }
    cout << endl;

    return 0;
}