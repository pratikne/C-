#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void recur_permutation(vector<int>& ds, vector<int>& arr, vector<vector<int>>& ans, int freq[]){
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }

    for(int i = 0; i < arr.size(); i++){
        if(!freq[i]){
            ds.push_back(arr[i]);
            freq[i] = 1;
            recur_permutation(ds,arr,ans,freq);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}

vector<vector<int>> permute(vector<int>& arr){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()]={};
    recur_permutation(ds,arr,ans,freq);
    return ans;
}

void subsequence(int ind, vector<int>& arr, int size, vector<int>& res){ // O(n * 2^n) TC , O(n) - SC
    if(ind == size){
        cout << "[Subsequence] : { ";
        for(auto i : res){
            cout << i << " ";
        }
        cout << "}" << endl;
        return;
    }
    
    res.push_back(arr[ind]);
    subsequence(ind+1, arr, size, res);
    res.pop_back();
    subsequence(ind+1, arr, size, res);
}

/**Subsequence -> Order to be maintained and can be contagious and non contagious members
 * also called subsets
 * 
 * Subarray -> need to be contagious
*/

void funsubset(int ind, int sum, vector<int>& arr, int N, vector<int>& sumsubset){
    if(ind == N){
        sumsubset.push_back(sum);
        return;
    }
    funsubset(ind+1, sum + arr[ind], arr, N, sumsubset); //Pick the element .. add in sum
    funsubset(ind+1, sum, arr, N, sumsubset); //Not Pick the element .. not to add in sum
}

vector<int> SubsetSum(vector<int>& arr, int N){
    vector<int> sumsubset;
    funsubset(0,0,arr,N,sumsubset);
    sort(sumsubset.begin(),sumsubset.end());
    return sumsubset;
}

int sumOfN(int num){ //O(n)
    // Base condition
    if(num == 0){
        return 0;
    }
    return num + sumOfN(num - 1);
}

int factorial(int num){ // O(n)
    // Base condition
    if(num == 0 || num == 1){
        return 1;
    }
    return num * factorial(num - 1);
}

int fibonacci_ind(int ind){
  if(ind==1)
      return 0;
  if(ind==2)
      return 1;
  return fibonacci_ind(ind-1) + fibonacci_ind(ind-2);
       
}

int fibonacci(int num){ // O(2^n)
    if(num==0 || num==1){
        return num;
    }
    return fibonacci(num-1) + fibonacci(num-2);
}


int main(){

    cout << fibonacci_ind(13) << endl;
    //-------------------------------------------------
    cout << factorial(5) << endl;
    //-------------------------------------------------
    cout << sumOfN(5) << endl;
    //-------------------------------------------------
    for(int i=0; i<5; i++){
        cout << fibonacci(i) << "\t";
    }
    cout << endl;
    //-------------------------------------------------
    vector<int> arr = {2,3,1};
    vector<int> ans = SubsetSum(arr,3);
    for(auto i : ans){
        cout << i << "\t";
    }
    cout << endl;
    //-------------------------------------------------
    vector<int> res;
    subsequence(0,arr,3,res);

    //-------------------------------------------------
    vector<vector<int>> ans2 = permute(arr);
    for(auto i : ans2){
        for(auto j : i){
            cout << j << "\t";
        }
        cout << endl;
    }
    return 0;
}
/**Other examples:
 * Mergesort
 * Quicksort
 * Tower of Hanoi
 * Tree Data structure
*/