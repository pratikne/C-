/***QUICK SORT ALGORITHM
 * Divide and conquer algorithm using internal memory...complete array is divided into two subparts till further division cant be done
 * and then..based on partition such that left side of partition is smaller than it and right side is bigger than it.
  TC -> O(nlogn) for Best case
  O(n*n) for worst case
  but, this algorithm is unstable(can be made stable if index are considered) and inplace(No extra space required)..hence used widely in various STL inbuilt libraries.
 PREFERRED :
 1) for comparatively smaller dataset (smaller size) as operation becomes quick
 2) Arrays
 ***/

#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v1, int l,int h){
    int pivot = v1[l];
    int i = l+1;
    int j = h;

    do{
        while(v1[i]<=pivot){
            i++;
        }
        while(v1[j]>pivot){
            j--;
        }
        if(i<j){
            swap(v1[i],v1[j]);
        }
    } while(i<j);

    swap(v1[l],v1[j]);
    return j;
}


int partition2(vector<int> &v1, int l,int r){ // l-leftmost, r-rightmost
    int pivot = v1[r];  //assume end element(r) as pivot
    int pInd = l;       //assume left index(l) as partition index

    /***loop from start to end-1 such that if any element if found <= pivot must be swapped with pInd element***/
    for(int i=l;i<=(r-1);i++){
        if(v1[i]<=pivot){
            swap(v1[i],v1[pInd]);
            pInd++;
        }
    }
        
    swap(v1[pInd],v1[r]); //At end..swap pivot with value at partition index
    return pInd;
}

void quicksort(vector<int> &v1, int l, int r){
    int partInd;
    if(l<r){
        partInd = partition2(v1,l,r);
        quicksort(v1,l,partInd-1);
        quicksort(v1,partInd+1,r);
    }
    return;
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
    quicksort(v1,0,v1.size()-1);
    cout<<"After sorting : "<<endl;
    printsort(v1);
    return 0;
}