/***QUICK SORT ALGORITHM
 * Divide and conquer algorithm using internal memory...complete array is divided into two subparts till further division cant be done
 * and then..based on partition such that left side of partition is smaller than it and right side is bigger than it.

1. An array is divided into subarrays by selecting a pivot element (element selected from the array).
2. While dividing the array, the pivot element should be positioned in such a way that elements less than pivot are kept on the left side and elements greater than pivot are on the right side of the pivot.
3. The left and right subarrays are also divided using the same approach. This process continues until each subarray contains a single element.
4. At this point, elements are already sorted. Finally, elements are combined to form a sorted array.

IMP*
  TC -> O(nlogn) for Best and Average case
  O(n*n) for worst case
  Unstable(can be made stable if index are considered) 
  Inplace(No extra space required)...hence used widely in various STL inbuilt libraries.

 PREFERRED :
 1) for comparatively smaller dataset (smaller size) as operation becomes quick
 2) Arrays
 ***/

#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v1, int l, int h)
{
    int pivot = v1[l]; // selecting leftmost as the pivot element
    int i = l + 1;
    int j = h;

    do
    {
        while (v1[i] <= pivot)
        {
            i++;
        }
        while (v1[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            swap(v1[i], v1[j]);
        }
    } while (i < j);

    swap(v1[l], v1[j]);
    return j;
}

int partition2(vector<int> &v1, int l, int r)
{                      // l-leftmost, r-rightmost
    int pivot = v1[r]; // assume rightmost element(r) as pivot
    int pInd = l;      // assume left index(l) as partition index

    /***loop from start to end-1 such that if any element if found <= pivot must be swapped with pInd element***/
    for (int i = l; i <= (r - 1); i++)
    {
        if (v1[i] <= pivot)
        { // v1[i] >= pivot for descending sort
            swap(v1[i], v1[pInd]);
            pInd++;
        }
    }

    swap(v1[pInd], v1[r]); // At end..swap pivot with value at partition index
    return pInd;
}

void quicksort(vector<int> &v1, int l, int r)
{
    int partInd;
    if (l < r)
    {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on righ of pivot
        partInd = partition2(v1, l, r);
        quicksort(v1, l, partInd - 1); // recursive call on the left of pivot
        quicksort(v1, partInd + 1, r); // recursive call on the right of pivot
    }
    return;
}

void printsort(const vector<int> &v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        cout << v1[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> v1;
    int a;
    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter a number : ";
        cin >> a;
        v1.push_back(a);
    }
    cout << "Before sorting : " << endl;
    printsort(v1);
    quicksort(v1, 0, v1.size() - 1);
    cout << "After sorting : " << endl;
    printsort(v1);
    return 0;
}