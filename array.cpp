#include<bits/stdc++.h>
using namespace std;

bool findXinKwindow(vector<int> &v, int X, int K){
    int i;
    cout<<v.size()<<endl;
    for(i=0; i<v.size(); i=i+K){
        int j;
        for(j=0; j<K; j++){
            if(v[i+j] == X)
                break;
        }
        if(j==K)
            return false;
    }
    /**if n multiple of X**/
    if(i==v.size())
        return true;
    
    /**if n not multiple of X**/
    int j;
    for(j=i-K; j<v.size(); j++){
        if(v[j]==X)
            break;
    }
    if(j==v.size())
        return false;
    
    return true;
}

void printvector(vector<int> &v){
    vector<int> :: iterator it;
    for(it=v.begin();it!=v.end();it++){
        cout<<*it<<" ";
    }
    cout<<endl;
}


bool compare(int a, int b){
    if(a<0)
        return true;
    return false;
}

int main(){

    int arr[] = {3,5,2,-4,9,3,1,-7,3,10,3};
    int N = sizeof(arr)/sizeof(arr[0]);
    //vector<int> v = {3,5,2,4,9,3,1,7,3,10,3};
    vector<int> v(arr,arr+N);
    int K = 3;
    int X = 3;
    if(findXinKwindow(v,X,K))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    int min_ele = *min_element(v.begin(),v.end()); //O(n)
    cout<<min_ele<<endl;
    int max_ele = *max_element(v.begin(),v.end()); //O(n)
    cout<<max_ele<<endl;

    cout<<"Range : "<<(max_ele - min_ele)<<endl;
    cout<<"Co-efficient of range : "<<(double) (max_ele - min_ele)/(max_ele + min_ele)<<endl;

    printvector(v);

    sort(v.begin(),v.end(),compare);   //O(nlogn)
    printvector(v);

    reverse(v.begin(),v.end());  //O(n)
    printvector(v);

    int k=2;
    cout<<k<<"th largest element : "<<v[v.size()-k]<<endl;
    cout<<k<<"th smallest element : "<<v[0 + k - 1]<<endl;

    int x = 3;
    int cnt = std::count(v.begin(),v.end(),x); //if using same variable name...we have to use std::
    cout<<"Freq of element "<<x<<" is "<<cnt<<endl;
    return 0;
}