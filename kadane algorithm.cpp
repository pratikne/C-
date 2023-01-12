#include <iostream>
using namespace std;

int maxSubArraySum(int a[], int n){

    int bestSum = INT_MIN;
    int currSum = 0; //for empty array {}

    for(int i=0; i < n; i++){

        currSum = currSum + a[i];

        if(currSum > bestSum){
            bestSum = currSum;
        }
        
        if(currSum < 0){
            currSum = 0;
        }
    }
    return bestSum;
}


int main(){
    int a[] = {-2,-3,4,-1,-2,1,5,-3};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "Max contiguous subarray sum is " <<  maxSubArraySum(a,n) << endl;

    return 0;
}