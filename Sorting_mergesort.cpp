/***MERGE SORT ALGORITHM

 * Divide and conquer algorithm using external memory...
 * complete array is divided into two subparts till further division cant be done
 * and then...that is sorted and finally merged.
 
  TC -> O(nlogn) for all cases
  Preferred for linked list or dataset of large size like E-commerce applications
  Stable algorithm 
  Not inplace as O(n) space complexity is required.
 ***/

#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v1, int l, int mid, int r) //n
{
    int i, j, k;

    // Create L ← A[p..q] and M ← A[q+1..r]
    int nl = (mid + 1) - l; // size of left array    0 1 2 3 4  Mid = 2 which will be included in larr
    int nr = r - mid;       // size of right array
    int larr[nl];           // left subarray
    int rarr[nr];           // right subarray

    for (i = 0; i < nl; i++)
    {                        // 0 1 2
        larr[i] = v1[l + i]; // starting from left
    }

    for (j = 0; j < nr; j++)
    {                              // 3 4
        rarr[j] = v1[mid + 1 + j]; // starting from mid+1
    }

    i = 0;
    j = 0;
    k = l; //IMP

    while (i < nl && j < nr)
    {
        if (larr[i] <= rarr[j])
        { // (larr[i] >= rarr[j]) for descending sort
            v1[k] = larr[i];
            i++;
            k++;
        }
        else
        {
            v1[k] = rarr[j];
            j++;
            k++;
        }
    }

    while (i < nl)
    { // If leftsubarray is still not completed
        v1[k] = larr[i];
        i++;
        k++;
    }

    while (j < nr)
    { // If rightsubarray is still not completed
        v1[k] = rarr[j];
        j++;
        k++;
    }
}

void mergesort(vector<int> &v1, int l, int r) //logn
{
    if (l < r)
    {
        int mid = l + (r - l) / 2; // (l + r) / 2;
        mergesort(v1, l, mid);     // [l , mid]
        mergesort(v1, mid + 1, r); // [mid+1 , r]
        merge(v1, l, mid, r);
    }
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
    mergesort(v1, 0, v1.size() - 1);
    cout << "After sorting : " << endl;
    printsort(v1);
    return 0;
}