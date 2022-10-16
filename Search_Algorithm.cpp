/**
Binary Search - applicable for sorted array - Divide and Conquer tactic
Time Complexity: O(log n)
Auxiliary Space: O(log n) - recursive, O(1) - iterative

Interpolation Search - sorted array - based on dictionary concept - divide and conquer tactic
Time complexity is improved over binary search O(logn(logn))

Linear Search - any array will do 
TC - O(n)
SC - O(1)
**/

#include<bits/stdc++.h>
using namespace std;

//Iterative
// A iterative binary search function. It returns
// location of x in given array arr[l..r] if present,
// otherwise -1
int binarySearchItr(int arr[], int l, int r, int x)
{
    while (l <= r) {
        int m = l + (r - l) / 2; //Calculates mid in circular concept
 
        // Check if x is present at mid
        if (arr[m] == x)
            return m;
 
        // If x greater, ignore left half
        if (arr[m] < x)
            l = m + 1;
 
        // If x is smaller, ignore right half
        else
            r = m - 1;
    }
    return -1;
}

//Recursive
int binarySearch(int arr[], int l, int r, int x)
{
    if (l <= r) {
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle itself
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid, then
        // it can only be present in left subarray
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        // in right subarray
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // We reach here when element is not
    // present in array
    return -1;
}

int interpolationSearch(int arr[], int lo, int hi, int x)
{
    int pos;
  
    // Since array is sorted, an element present
    // in array must be in range defined by corner
    if (lo <= hi && x >= arr[lo] && x <= arr[hi]) {
  
        // Probing the position with keeping
        // uniform distribution in mind.
        //pos = l + (h-l)*((data-l)/(h-l))
        pos = lo + ((double)(hi - lo) *  ((x - arr[lo])/(arr[hi] - arr[lo])));
  
        // Condition of target found
        if (arr[pos] == x)
            return pos;
  
        // If x is larger, x is in right sub array
        if (arr[pos] < x)
            return interpolationSearch(arr, pos + 1, hi, x);
  
        // If x is smaller, x is in left sub array
        if (arr[pos] > x)
            return interpolationSearch(arr, lo, pos - 1, x);
    }
    return -1;
}

int main(void)
{
    int arr[] = { 2, 3, 4, 10, 40 };
    int x = 10;
    int n = sizeof(arr) / sizeof(arr[0]); //Calculates size of array
    
    //sort(arr,arr+n);  --if not sorted, then sort it first
    int result = binarySearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array\n"
        : cout << "Element is present at index \n" << result;

    result = binarySearchItr(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array\n"
        : cout << "Element is present at index \n" << result;
    result = interpolationSearch(arr, 0, n - 1, x);
    (result == -1)
        ? cout << "Element is not present in array\n"
        : cout << "Element is present at index \n" << result;
    return 0;
}

/**
Output
Element is present at index 3
**/