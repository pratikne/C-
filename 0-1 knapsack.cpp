/**
 * @file 0-1 knapsack.cpp
 * 
 * By Aditya Verma
 * 1) Subset = Sum
 * 2) Equal sum partition
 * 3) Count of subset sum
 * 4) Minimum subset sum diff
 * 5) Target sum(+/-)
 * 6) Count of subset which gives diff x
 * 
 */

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

int tp[3+1][50+1]; //t[n+1][w+1]
int c = 0;

//arr given would be considered as wt
//sum would be considered as w
bool SubsetSum(int wt[], int sum, int n){
    vector<vector<int>> t(n+1,vector<int>(sum+1));

    for(int i=0; i < n+1; i++){ //Base condition <> Init
        for(int j=0; j < sum+1; j++){
            if(i==0)
                t[i][j]=false;
            if(j==0)
                t[i][j]=true;
        }
    }
    for(int i=1; i < n+1; i++){
        for(int j=1; j < sum+1; j++){
            if(wt[i-1]<=j)
                t[i][j]= t[i-1][j-wt[i-1]] || t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }

    return t[n][sum];
}

int CountSubsetSum(int wt[], int sum, int n){
    vector<vector<int>> t(n+1,vector<int>(sum+1));

    for(int i=0; i < n+1; i++){ //Base condition <> Init
        for(int j=0; j < sum+1; j++){
            if(i==0)
                t[i][j]=0; //false -> 0
            if(j==0)
                t[i][j]=1; //true -> 1
        }
    }
    for(int i=1; i < n+1; i++){
        for(int j=1; j < sum+1; j++){
            if(wt[i-1]<=j)
                t[i][j]= t[i-1][j-wt[i-1]] + t[i-1][j];
            else
                t[i][j]=t[i-1][j];
        }
    }

    return t[n][sum];
}

bool equalsumpartision(int wt[], int n){
    long sum = 0;
    for(int i=0; i < n; i++){
        sum = sum + wt[i];
    }
    if(sum%2 != 0) //if odd sum..no chance of equal partision
        return false;
    else   //if even...there is possibility of equal partision..just check half of it through subsetsum
        return SubsetSum(wt,sum/2,n);
}

int IterativeKnapsnap(int wt[], int val[], int w, int n){ //Bottom up 
//n(i) and w(j)
    vector<vector<int>> t(n+1,vector<int>(w+1));
    int maxprofit=0;
    for(int i=0; i < n+1; i++){ //Base condition <> Init
        for(int j=0; j < w+1; j++){
            if(i==0 || j==0)
                t[i][j]=0;
        }
    }

    for(int i=1; i < n+1; i++){
        for(int j=1; j < w+1; j++){
            if(wt[i-1]<=j)
                t[i][j]=max(val[i-1] + t[i-1][j-wt[i-1]], t[i-1][j]);
            else
                t[i][j]=t[i-1][j];

        }
    }

    return t[n][w];
}

int Knapsnap(int wt[], int val[], int w, int n){ //Top down ->Recursive
//Memoization can also be done..done below
    //static vector<vector<int>> t(n+1,vector<int>(w+1));
    if(c<1){
        c++;
        memset(tp,-1,sizeof(tp));
    }
    if( n==0 || w==0 )
        return 0;
    if( tp[n][w] != -1)
        return tp[n][w];
    if( wt[n-1] <= w ) // if wt of item is within the desired, we have to choose it or not to et max
        return tp[n][w]=max(val[n-1] + Knapsnap(wt,val,w-wt[n-1],n-1), Knapsnap(wt,val,w,n-1));
    else
        return tp[n][w]=Knapsnap(wt,val,w,n-1); //if wt of items more than sack, skip that item


}

int main()
{
    int wt[] = {10,20,30};
    int val[] = {60,100,120};
    int W = 50;
    
    int maxProfit = Knapsnap(wt,val,W,sizeof(wt)/sizeof(wt[0]));
    cout << "maxProfit : " << maxProfit << endl;
    int maxProfit2 = IterativeKnapsnap(wt,val,W,sizeof(wt)/sizeof(wt[0]));
    cout << "maxProfit : " << maxProfit2 << endl;

    cout << "Is wt subset of sum 40 : " << SubsetSum(wt,40,3) << endl;
    cout << "Is wt equal partision subset : " << equalsumpartision(wt,3) << endl;
    cout << "Count of subset of sum 30 : " << CountSubsetSum(wt,30,3) << endl;
    
    
    

/**
    for(int i=0; i < 3+1; i++){ //Base condition <> Init
        for(int j=0; j < 50+1; j++){
            cout << tp[i][j] << " ";
        }
        cout << endl;
    }**/

    return 0;
}