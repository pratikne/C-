// https://www.bogotobogo.com/DesignPatterns/strategy.php
// Look for Youtube channel --> BBarters for strategy pattern (Soldier game))

/**
 * We have two interfaces: SortBehavior and SearchBehavior along with corresponding classes that implement each concrete behavior.
 * With the design, other types of objects can reuse our search and sort behaviors because these behaviors are no longer hidden away in our Collection classes.
 * And we can add new behaviors without modifying any of our existing behavior classes.
 * We put instance variables hold a pointer to a specific behavior at runtime.
 * We do not care what kind of collection object it is, all we care about is that it knows how to sort()
 * Actually, we've created system using composition giving us a lot more flexibility. Not only does it let us encapsulate a family of algorithm into their own set of classes, but it also let us change behavior at runtime as long as the object we're composing with implements the correct behavior interface.
 */

#include <iostream>
using namespace std;


//IStrategy1 for Sorting ALgo --> {Merge, Quick, Heap}
class SortBehavior //Abstract class - Interface
{
public:
    virtual void sort() const = 0;
};

class Merge : public SortBehavior
{
public:
    virtual void sort() const
    {
        cout << "Merge sort()\n";
    }
};

class Quick : public SortBehavior
{
public:
    virtual void sort() const
    {
        cout << "Quick sort()\n";
    }
};

class Heap : public SortBehavior
{
public:
    virtual void sort() const
    {
        cout << "Heap sort()\n";
    }
};


//IStrategy2 for Search ALgo --> {Sequential, Binary, Hash}
class SearchBehavior //Abstract class - Interface
{
public:
    virtual void search() const = 0;
};

class Sequential : public SearchBehavior
{
public:
    virtual void search() const
    {
        cout << "Sequential search()\n";
    }
};

class BinaryTree : public SearchBehavior
{
public:
    virtual void search() const
    {
        cout << "BinaryTree search()\n";
    }
};

class HashTable : public SearchBehavior
{
public:
    virtual void search() const
    {
        cout << "HashTable search()\n";
    }
};


// Context / Client
class Collection
{
private:
    SortBehavior *m_sort;
    SearchBehavior *m_search;

public:
    Collection() {}
    void set_sort(SortBehavior *s)
    {
        m_sort = s;
    }
    void set_search(SearchBehavior *s)
    {
        m_search = s;
    }
    void sort() const
    {
        m_sort->sort();
    }
    void search() const
    {
        m_search->search();
    }
};

int main(int argc, char *argv[])
{s
    Merge merge;
    Quick quick;
    Heap heap;

    Sequential sequential;
    BinaryTree binaryTree;
    HashTable hashTable;

    Collection colA;
    colA.set_sort(&merge);
    colA.sort();

    Collection colB;
    colB.set_search(&binaryTree);
    colB.search();

    return 0;
}

//  OUTPUT
//  Merge sort()       
//  BinaryTree search()