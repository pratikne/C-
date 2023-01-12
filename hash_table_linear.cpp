/**A hash map is a data structure which is used to store key-value pairs.
 * Hash function is used by hash table to compute an index into an array in which an element will be inserted or searched.
 * why hash function ?
 * 1. key conversion
 * 2. uniform distribution
 *
 * Hashing is a popular technique for storing and retrieving data as fast as possible giving optimal results O(1) amortized TC
 *
 * All operations done in average case of O(1) i.e constant time, worst case do remains O(n)
 * 1. Linear probing (explained in this example)
 * 2. Chaining (explained next example)
 *
 * Collision - when multiple values get same key after hashing function stage
 * Prevention (2 ways)
 * 1. Open hashing (put it in same place) - can be done through chaining via linked list
 * 2. Closed Addressing (explained in this example)
 *   * Linear Probing H(a) = h() + i
 *   * Quadratic Probing H(a) = h() + i*i
 *
 *
 * int h = HashFunc(k);
 * h = HashFunc(h+1) //Linear
 * Mostly, such hash functions are used which does uniform distribution.
 **/
#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
using namespace std;
const int BUCKET_SIZE = 20;

class HashTableEntry
{
public:
   int k;
   int v;

   HashTableEntry(int k, int v)
   {
      this->k = k;
      this->v = v;
   }
};

class HashMapTable
{
private:
   HashTableEntry **t; 
   // t = new HashTableEntry* [BUCKET_SIZE];

public:
   HashMapTable()
   {
      // Initialize double pointer
      t = new HashTableEntry* [BUCKET_SIZE];
      // Initialize single pointers within
      for (int i = 0; i < BUCKET_SIZE; i++)
      {
         t[i] = NULL;
      }
   }

   // provided given key, it returns index
   int HashFunc(int k)
   {
      return (k % BUCKET_SIZE);
   }

   void Insert(int k, int v) // Average O(1)
   { // O(1)
      int h = HashFunc(k);
      while (t[h] != NULL && t[h]->k != k)
      {
         h = HashFunc(h + 1);
      }
      if (t[h] != NULL)
      {
         delete t[h]; // delete previous entry at that key
         t[h] = NULL;
      }

      t[h] = new HashTableEntry(k, v); // inerts new entry at that key
   }

   int SearchKey(int k) // Average O(1)
   { // O(1) average and O(n) when worst
      int h = HashFunc(k);
      while (t[h] != NULL && t[h]->k != k)
      {
         h = HashFunc(h + 1);
      }
      if (t[h] == NULL)
         return -1;
      else
         return t[h]->v;
   }

   void Remove(int k) // Average O(1)
   { // O(1)
      int h = HashFunc(k);
      while (t[h] != NULL && t[h]->k != k)
      {
         // if (t[h]->k == k)
         //    break;
         h = HashFunc(h + 1);
      }
      if (t[h] == NULL)
      {
         cout << "No Element found at key " << k << endl;
         return;
      }
      else
      {
         delete t[h];
         t[h] = NULL;
      }
      cout << "Element Deleted" << endl;
   }

   void display() 
   {
      for (int i = 0; i < BUCKET_SIZE; i++)
      {
         if (t[i] != NULL)
         {
            cout << " (" << t[i]->k << "," << t[i]->v << ") ";
         }
         else
         {
            cout << " (~,~) ";
         }
      }
      cout << endl;
   }

   ~HashMapTable()
   {
      for (int i = 0; i < BUCKET_SIZE; i++)
      {
         if (t[i] != NULL)
            delete t[i];
      }
      delete[] t;
   }
};
int main()
{
   HashMapTable hash;
   int k, v;
   int c;
   while (1)
   {
      cout << "---------------MENU DRIVEN PROGRAM----------------" << endl;
      cout << "1.Insert element into the table" << endl;
      cout << "2.Search element from the key" << endl;
      cout << "3.Delete element at a key" << endl;
      cout << "4.Display the Hash Table" << endl;
      cout << "5.Exit" << endl;
      cout << "Enter your choice: ";
      cin >> c;
      cout << "-----------------------------------------------" << endl;
      switch (c)
      {
      case 1:
         cout << "Enter element to be inserted: ";
         cin >> v;
         cout << "Enter key at which element to be inserted: ";
         cin >> k;
         hash.Insert(k, v);
         break;
      case 2:
         cout << "Enter key of the element to be searched: ";
         cin >> k;
         if (hash.SearchKey(k) == -1)
         {
            cout << "No element found at key " << k << endl;
            continue;
         }
         else
         {
            cout << "Element at key " << k << " : ";
            cout << hash.SearchKey(k) << endl;
         }
         break;
      case 3:
         cout << "Enter key of the element to be deleted: ";
         cin >> k;
         hash.Remove(k);
         break;
      case 4:
         hash.display();
         break;
      case 5:
         exit(1);
      default:
         cout << "\nEnter correct option\n";
      }
   }
   return 0;
}