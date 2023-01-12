/**************VECTOR IMPLEMENTATION***************/
/** they are dynamic array storing values in continuous memory **/
/**combo of linked list and array best feature**/
/*remove from end is O(1)
 *remove from start is O(n)
 *insert at end is amortized O(1)...(rarely O(n) which can be ignored)
 *access O(1)
 *insert/remove from mid(m) O(m)*/

#include <bits/stdc++.h>
#include <iostream>
#include <vector> //this is must for implementing vector
//#define push_back pb;
using namespace std;

void print(const vector<int> &v)
{
    cout << "[VECTOR] ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

int main()
{

    vector<int> v1;                                    // declares blank vector of size 0
    vector<int> p1(5);                                 // vector p1 is declared of size 5
    vector<int> p2(5, 10);                             // vector p2 is declared of size 5 and 10 is filled in all..default 0
    vector<int> p3[5];                                 // array of vectors p3 is declared of size 5
    vector<vector<int>> matrix(5, vector<int>(5, -1)); // 2D vector-matrix for DP
    vector<int>::iterator i;

    i = v1.begin();
    advance(i, 5); // applicable
    // no sort and reverse function inbuilt for vector.....have to use algorithm sort and reverse for it.
    // also no push_front and pop_front available but we can use insert and erase for the same.

    vector<int>::reverse_iterator ir;
    v1.push_back(10);
    v1.push_back(12);
    v1.push_back(15);

    /**
        for(i = v1.begin(); i != v1.end(); i++){
            cout<<*i<<endl;
        }

        for(ir = v1.rbegin(); ir != v1.rend(); ir++){   //traverse in reverse order
            cout<<*ir<<endl;
        }
    **/
    cout << "Size of vector : " << v1.size() << endl;
    cout << "Capacity of vector : " << v1.capacity() << endl;
    v1.resize(2);
    cout << "Size of vector : " << v1.size() << endl;
    cout << "Capacity of vector : " << v1.capacity() << endl;

    print(v1);

    v1.clear();
    cout << "Size of vector : " << v1.size() << endl;
    cout << "Capacity of vector : " << v1.capacity() << endl;

    print(v1);

    // v1.reserve(2);
    // v1.shrink_to_fit();
    cout << "Size of vector : " << v1.size() << endl;
    cout << "Max Size of vector : " << v1.max_size() << endl;
    cout << "Capacity of vector : " << v1.capacity() << endl;

    if (v1.empty())
        cout << "Vector is empty";
    else
        cout << "Not empty";

    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);

    // cout<<v1.at(3)<<endl;  //gives error as 3rd position is out of range
    cout << v1[3] << endl; // still runs fine but gives garbage value/0

    cout << "Front element is " << v1.front() << endl; // 10
    cout << "Back element is " << v1.back() << endl;   // 30

    v1.pop_back(); // removes last element i.e 30
    print(v1);

    vector<int> v2(v1); // copy v1 to v2
    print(v2);

    vector<int> v3(3, 10); // initialize vector of size 3 with 10 as element
    print(v3);

    // v.insert(v.pos, start, end)
    v2.insert(v2.begin() + 2, v3.begin(), v3.end()); // start inserting from 2nd index
    print(v2);

    cout << "[ERASE]" << endl;
    v2.erase(v2.begin() + 1); // removes element at 1st index
    print(v2);

    v1.swap(v2); // does in constant time....

    vector<pair<string, int>> vp;
    // vector<pair<string,int> > :: iterator it;

    vp.push_back(make_pair("Pratik", 1));
    vp.push_back(make_pair("Ritik", 2));

    for (int i = 0; i < vp.size(); i++)
    {
        cout << vp[i].first << " " << vp[i].second << endl;
    }

    // Algorithm we can do in vectors and array
    reverse(v2.begin(), v2.end());  //O(n)
    cout << "After reversing v2 : ";
    print(v2);

    // sort(v2.begin(),v2.end(), greater<int>()); //desc
    sort(v2.begin(), v2.end()); // default less<int>() asc  o(nlogn)
    cout << "After sorting v2 : ";
    print(v2);

    cout << "Max element : " << *max_element(v2.begin(), v2.end()) << endl;
    cout << "Min element : " << *min_element(v2.begin(), v2.end()) << endl;

    // immediate big element of that
    cout << "Upper bound : " << *upper_bound(v2.begin(), v2.end(), 20) << endl;
    // equal(1st occurence) or immediate big element of that
    cout << "Lower bound : " << *lower_bound(v2.begin(), v2.end(), 10) << endl;
    cout << "Binary serach : " << binary_search(v2.begin(), v2.end(), 20) << endl;
    // NOTE : Binary search, Upper and lower bound works only in asc sorted vector/array in logN time

    cout << "Sum of ele : " << accumulate(v2.begin(), v2.end(), 0) << endl; // initial sum = 0
    cout << "Count of element : " << count(v2.begin(), v2.end(), 10) << endl;
    // finds count of 10 in the vector..if count 0, element not present

    vector<int>::iterator ite = find(v2.begin(), v2.end(), 10);
    if (ite != v2.end())
        cout << *ite << endl;
    else
        cout << "Element not found";

    v2.push_back(50);
    v2.push_back(100);
    v2.push_back(50);
    // sort(v2.begin(),v2.end());
    print(v2);

    vector<int>::iterator ip;
    ip = unique(v2.begin(), v2.end()); // returns pointer to last element
    // NOTE : Duplicate elements present consecutely will be deleted..if you want all unique elements..then sort it first
    v2.resize(distance(v2.begin(), ip));

    prev_permutation(v2.begin(), v2.end()); // returns true/false
    // no need to be sorted...if already permuted to least selection...will return false and give max permutation of higher order.
    print(v2);
    next_permutation(v2.begin(), v2.end()); // no need to be sorted
    print(v2);

    cout << distance(v2.begin(), max_element(v2.begin(), v2.end())) << endl;
    // gives the distance between starting and that element pointer by iterator
    vector<int>::iterator newit;
    newit = remove(v2.begin(), v2.end(), 10);
    v2.erase(newit, v2.end()); // O(n)
    print(v2);
    // removes 10 from the vector
    return 0;
}