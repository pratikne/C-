#include <iostream>
#include <math.h> //for ceil and log2

using namespace std;

class MinHeap
{
public:           // for simplicity purpose
    int *harr;    // pointer to array of elements in heap
    int capacity; // maximum possible size of min heap
    int size;     // current number of elements in min heap

    MinHeap(int cap)
    { // Constructor for MinHeap
        harr = new int[cap];
        capacity = cap;
        size = 0;
    }

    void linearSearch(int val)
    { // O(n)
        for (int i = 0; i < size; i++)
        {
            if (harr[i] == val)
            {
                cout << "Value found" << endl;
                return;
            }
        }
        cout << "Value Not found" << endl;
        return;
    }

    void printHeapArray()
    { // O(n)
        for (int i = 0; i < size; i++)
        {
            cout << harr[i] << " ";
        }
        cout << endl;
    }

    int height()
    {
        return ceil(log2(size + 1)) - 1;
    }

    // Returns Parent index for the given ind
    int parent(int i)
    {
        return (i - 1) / 2; // parent_ind = (child_ind - 1) / 2
    }

    // Returns left child index for the given ind
    int leftchild(int i)
    {
        return (2 * i + 1); // leftchild_ind = (2 * i + 1)
    }

    // Returns right child index for the given ind
    int rightchild(int i)
    {
        return (2 * i + 2); // rightchild_ind = (2 * i + 2)
    }

    void swap(int &x, int &y)
    { // Swap using ref
        int temp = x;
        x = y;
        y = temp;
    }

    void insertKey(int k) //logN
    {
        if (size == capacity)
        {
            cout << "Overflow : Could not insert! \n";
            return;
        }
        // first insert new key at the end
        size++; // One insert at a time will increase the size of heap by 1
        int i = size - 1;
        harr[i] = k;
        cout << "Value inserted\n";

        // Fix the MinHeap property if it gets violated (Parent node > child nodes)
        while (i != 0 && harr[parent(i)] > harr[i])
        {
            swap(harr[parent(i)], harr[i]);
            i = parent(i); // going from bottom to top of tree (child to parent)
        }
    }

    int getMin()
    {
        return harr[0]; // 0th index of MinHeap will always have Min value
    }

    // Creates Min-Heap
    // Recursive function
    void MinHeapify(int i) //logN
    {
        // int size = hT.size();
        int smallest = i;      // Parent index
        int l = leftchild(i);  // Left child, we are using from 0th index
        int r = rightchild(i); // Right child, we are using from 0th index

        // check if left child is smaller
        if (l < size && harr[l] < harr[smallest])
            smallest = l;
        // check if right child is smaller
        if (r < size && harr[r] < harr[smallest])
            smallest = r;

        if (smallest != i)
        {
            swap(harr[i], harr[smallest]);
            MinHeapify(smallest);
        }
    }

    // Deletes Min value i.e first element from Heap
    int extractMin() //logN
    {
        if (size <= 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return harr[0];
        }
        else
        {
            // STore the min value and remove it from heap(overwrite it by assigning last and reducing size)
            int mini = harr[0];       // Min is at start which is saved and is returned later
            harr[0] = harr[size - 1]; // Assign last to first and reduce the size OR swap them
            size--;
            MinHeapify(0);
            return mini;
        }
    }

    void Sort(){ //nlogn
        int temp[size];
        int s = size;
        for(int i=0; i<s; i++){
            temp[i] = extractMin();
        }
        for(int i=0; i<s; i++){
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    void deleteKey(int val) //Average - logn, worst - O(n)
    {
        int i;
        for (i = 0; i < size; i++)
        {
            if (val == harr[i])
                break;
        }

        if(i == size){
            cout << "Value not found" << endl;
            return;
        }

        swap(harr[i], harr[0]); // put the value at first index which you want to delete
        extractMin();           // extractMin will delete the 1st element and will Heapify it again 
        cout << "Value Deleted" << endl;
    }

    ~MinHeap()
    {
        if (harr != NULL)
        {
            delete[] harr;
            harr = NULL;
            cout << "Destructor called!" << endl;
        }
    }
};

int main()
{
    int s;
    cout << "Enter size of Min Heap" << endl;
    cin >> s;

    MinHeap obj(s);
    cout << "MinHeap Created" << endl;

    int option; // for menu driven options
    int val;

    do
    {
        cout << "--------------------------------------------" << endl;
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Value" << endl;
        cout << "2. Search Value" << endl;
        cout << "3. Delete Value" << endl;
        cout << "4. Get Min value" << endl;
        cout << "5. Delete Min / Extract Min" << endl;
        cout << "6. Height of Heap" << endl;
        cout << "7. Print/Traversal Heap values" << endl;
        cout << "8. Sort the Heap in Ascending order" << endl;
        cout << "9. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;
        cout << "---------------------------------------------" << endl;

        cin >> option;

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT Operation -" << endl;
            cout << "Enter VALUE to INSERT in HEAP: ";
            cin >> val;
            obj.insertKey(val);
            cout << endl;
            break;
        case 2:
            cout << "SEARCH Operation -" << endl;
            cout << "Enter VALUE to SEARCH in HEAP: ";
            cin >> val;
            obj.linearSearch(val);
            break;
        case 3:
            cout << "DELETE Operation -" << endl;
            cout << "Enter INDEX of Heap Array to DELETE: ";
            cin >> val;
            obj.deleteKey(val);
            break;
        case 4:
            cout << "GET Min value : " << obj.getMin();
            cout << endl;
            break;
        case 5:
            cout << "EXTRACT Min value : " << obj.extractMin();
            cout << endl;
            break;
        case 6:
            cout << "HEAP TREE HEIGHT : " << obj.height() << endl;
            break;
        case 7:
            cout << "PRINT Heap Array : " << endl;
            obj.printHeapArray();
            cout << endl;
            break;
        case 8:
            cout << "SORT ASCENDING : " << endl;
            obj.Sort();
            cout << endl;
            break;
        case 9:
            system("cls");
            break;

        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}