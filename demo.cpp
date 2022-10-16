#include<bits/stdc++.h>
#include <vector>
#include <cmath>
#define SIZE 10
using namespace std;

int main(int argc, char const *argv[])
{
    /* code */
    //cout << "PRATIK";
    vector<int> V;
    V.resize(256);
    for(int i =0; i < 200 ; i++)
        V.push_back(i);
    cout<<V.size()<<endl;
    for(int i =1; i < 100 ; i++)
        V.push_back(i+500);
    cout<<V.size()<<endl;
    char carr[] = {'q','w','e','r','a'};
    int n = sizeof(carr)/sizeof(carr[0]);
    vector<char> v2(carr,carr+n);
    cout << "Max element : "<< *max_element(v2.begin(),v2.end())<<endl;
    cout << "Min element : "<< *min_element(v2.begin(),v2.end())<<endl;
    char arr[SIZE];
    cin >> setw(SIZE) >> arr ;
    cout<<setw(SIZE);
    cout<<arr<<endl;

    cout << (int) sqrt(26) <<endl;  //returns double

    return 0;
}
