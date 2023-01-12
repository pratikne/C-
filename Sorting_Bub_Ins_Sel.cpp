/***BUBBLE_SORT / INSERTION_SORT / SELECTION_SORT ***/

#include<bits/stdc++.h>
using namespace std;


/***Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration.
Insertion sort works similarly as we sort cards in our hand in a card game.
The first element in the array is assumed to be sorted. Take the second element and store it separately in key***/

/**Best case - O(n)
 * Worst case - O(n*n)
 * Insertion Sort = Shifting
 * In-place, Stable
 **/

void insertionsort(vector<int> &v1){
    int key,j;
    int n = v1.size();

    for(int i=1; i<n; i++){  //each pass
        key = v1[i];
        j = i-1;

        while(j>=0 && v1[j] > key){  // v1[j] < key for descending sort
            //smallest element will be placed at the start and rest will shifted by 1 to right
            v1[j+1] = v1[j];
            j--;
        }
        v1[j+1] = key;
    }
}


/***At each pass....smallest element is found out and swapped with the element at each index ***/

/**Best case - O(n*n)
 * Worst case - O(n*n)
 * Inplace sorting algorithm(No extra memory required)
 * Not stable like quicksort
 * 
 * Adv over bubble sort ::: cost of writing to a memory matters like in flash memory (number of writes/swaps is O(n) as compared to O(n2) of bubble sort)
 **/
void selectionsort(vector<int> &v1){
    int minInd;
    int n = v1.size();

    for(int i=0; i<(n-1); i++){  //each pass( 1 less till n-2)
        minInd = i;

        // Select the minimum element in each loop.
        for(int j = i+1; j<n; j++){
            // v1[j] > v1[minInd]   for descending sort
            if(v1[j] < v1[minInd]) //smallest element found out and its index saved in minInd
                minInd = j;
        }
        // put min at the correct position
        swap(v1[minInd],v1[i]);
    }
}


/***In this, largest element is found and placed at the end...
 *  for next loop...second largest element is found and placed at the second largest position***/

/**Best case - O(n)  ..if checked for sorted loop at very first pass(Adaptive use)
 * Worst case - O(n*n)
 * Bubble Sort = Swapping
 * Inplace sorting - No extra scape required
 * Stable sorting - same value position isnt changed
 **/
void bubblesort(vector<int> &v1){
    //int temp;
    int n = v1.size();
    bool isSorted;  
    for(int i=0;i<n-1;i++){  //each pass....till n-2
        isSorted = true;
        for(int j=0;j<(n-1-i);j++){ //comparisions in each pass
            if(v1[j] > v1[j+1]){  // v1[j] < v1[j+1] for descending sort
                swap(v1[j],v1[j+1]);
                isSorted=false;  //ek bhi swap means issorted flag is false
            }
        }
        if(isSorted){ //if sorted(true)...value would be 1
            return;
        }
    }

}

void printsort(const vector<int> &v1){
    for(int i = 0; i < v1.size(); i++){
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> v1;
    int a;
    for(int i = 1; i <= 5; i++){
        cout<<"Enter a number : ";
        cin>>a;
        v1.push_back(a);
    }
    cout<<"Before sorting : "<<endl;
    printsort(v1);
    //bubblesort(v1);
    insertionsort(v1);
    //selectionsort(v1);
    cout<<"After sorting : "<<endl;
    printsort(v1);
    return 0;
}