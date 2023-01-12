/**A hash map is a data structure which is used to store key-value pairs.
 * Hash function is used by hash table to compute an index into an array in which an element will be inserted or searched.
 * why hash function ?
 * 1. key conversion
 * 2. uniform distribution
 *
 * Hashing is a popular technique for storing and retrieving data as fast as possible giving optimal results O(1) amortized TC
 *
 * All operations done in average case of O(1) i.e constant time, worst case do remains O(n)
 * 1. Linear probing 
 * 2. Chaining 
 *
 * Collision - when multiple values get same key after hashing function stage
 * Prevention (2 ways)
 * 1. Open hashing (put it in same place) - can be done through chaining via linked list (explained below)
 * 2. Closed Addressing (explained in hash_table_linear.cpp example)
 *   * Linear Probing H(a) = h() + i
 *   * Quadratic Probing H(a) = h() + i*i
 *
 *
 * int h = HashFunc(k);
 * h = HashFunc(h+1) //Linear
 * Mostly, such hash functions are used which does uniform distribution.
 
 APPLICATIONS::
 . constant time lookup
 . indexing data as in DB's
 **/

#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int BUCKET; // No. of buckets

    // Pointer to an array of lists containing buckets
    // similar to int* harr, but we want it for list<int>
    list<int>* table;

public:
    Hash(int V); // Constructor

    // inserts a key into hash table
    void insertItem(int x);

    // deletes a key from hash table
    void deleteItem(int key);

    // hash function to map values to key
    int hashFunction(int x)
    {
        return (x % BUCKET);
    }

    void displayHash();
};

Hash::Hash(int b)
{
    BUCKET = b;
    table = new list<int>[BUCKET]; //list array 
}

void Hash::insertItem(int key)
{
    int index = hashFunction(key);
    table[index].push_back(key);
}

void Hash::deleteItem(int key)
{
    // get the hash index of key
    int index = hashFunction(key);

    // find the key in (index)th list
    list<int>::iterator it;
    for (it = table[index].begin();
         it != table[index].end(); it++)
    {
        if (*it == key)
            break;
    }

    // if key is found in hash table, remove it
    if (it != table[index].end())
        table[index].erase(it);
}

// function to display hash table
void Hash::displayHash()
{
    for (int i = 0; i < BUCKET; i++)
    {
        cout << i;
        for (auto x : table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

// Driver program
int main()
{
    // array that contains keys to be mapped
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    // insert the keys into the hash table
    Hash h(7); // 7 is count of buckets in
               // hash table
    for (int i = 0; i < n; i++)
        h.insertItem(a[i]);

    // delete 12 from hash table
    h.deleteItem(12);

    // display the Hash table
    h.displayHash();

    return 0;
}