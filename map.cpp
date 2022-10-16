/**************MAP IMPLEMENTATION***************/

/*Map internally implemented via RBT(Red black tree)...not of continuous memory
 * Data stored in (key,value) pair..key always unique

 * 1) Map (self balancing BST) --> sorted order on basis on key which are unique
 * 2) Unordered_Map (Hash map) --> random order*........uses HASH table internally
 * 
 * 
                | map                 | unordered_map
---------------------------------------------------------
Ordering        | increasing  order   | no ordering
                | (by default)        |

Implementation  | Self balancing BST  | Hash Table
                | like Red-Black Tree |  

search time     | log(n)              | O(1) -> Average 
                |                     | O(n) -> Worst Case

Insertion time  | log(n) + Rebalance  | Same as search
                      
Deletion time   | log(n) + Rebalance  | Same as search

Time complexity | Slow                | Fast

Space complexity| O(n)                | O(n)
*/
#include <bits/stdc++.h>
#include <iostream>
#include <map>   //this is must for implementing map
//#include <unordered_map> //must for unordered map
using namespace std;

void print(map<int, string> &m){  //O(nlogN)
    map<int, string> :: iterator it;
    cout<< "Size of below map : "<<m.size()<<endl;
    for(it=m.begin(); it!=m.end();it++){
        cout<<it->first<<" "<<it->second<<endl;
    }
}


int main(){
    map<int, string> m;
    //unordered_map<string, int> umap;

    //map<int, string, greater<int> > m1;  for storing in desc order of key values.
    map<int, string> :: iterator it;
    m[1] = "Pratik";
    m[5] = "Hi All";
    m.insert(make_pair(3,"Ardeep"));  //takes O(logN) time...for above as well.
    m[4];   //string will be initialed with default NULL value....same for other datatypes
    m[5] = "Ritik";   //value of 5th key is modified.....wont insert new map of same key
    print(m);

    it = m.find(3);   //finds if key 3 is present or not..takes O(logN) time
    if(it != m.end())
        cout<<"Key found."<<" Value is : "<<it->second<<endl;  //(*it).second
    else
        cout<<"Key not found."<<endl;

    m.erase(4); //erases map with key given as input.......O(logN)
    print(m);

    it=m.begin();
    it++;  //points to second pair in the map
    advance(it,5);
    if(it != m.end())
        m.erase(it);  //here, passing iterator (key can also be passed)
        //m.erase(it,it.end())  --[start,end) is erased
        //erases that pair pointed by the iterator.....but if bymistake we give iterator which is pointing beyong the range..it will give segmentation fault
    print(m);

    //m.clear();   //clear entire map
    //print(m);

/**
    map<string , string> m2 ;
    m2["Pratik"] = "Negi";  
    m2["Ritik"] = "Negi";  //O(keystring.size() * logN)  time
    m2["Ardeep"] = "Negi";
**/
    cout<<"Upper bound :"<<endl;
    cout<<m.upper_bound(4)->second<<endl;
    cout<<"Lower bound :"<<endl;
    cout<<m.lower_bound(4)->second<<endl;

    return 0;
}