#include <bits/stdc++.h>
using namespace std;
/****OOPS 4 features (A PIE / I APE)
 * A->Abstraction
 * P->Polymorphism
 * I->Inheritance
 * E->Encapsulation
 * 
 *> Data encapsulation is a mechanism of bundling the data, and the functions that use them 
 *> Data abstraction is a mechanism of exposing only the interfaces 
 and hiding the implementation details from the user.
 ****/

/** ACCESS MODIFIERS -> supports ABSTRACTION within ENCAPSULATED format....data hiding for increased security
 * 1) PRIVATE (own class- yes, derived/child class- no, outside class-no)
 * 2) PUBLIC (own class- yes, derived/child class- yes, outside class-yes)
 * 3) PROTECTED (own class- yes, derived/child class- yes, outside class-no)
**/

/**LEVELS OF INHERITANCE
 * 1) SINGLE (A->B) ...B inher. from A
 * 2) MULTIPLE (A->B<-C)  .....B inherting from A as well as C
 * 3) MULTILEVEL (A->B->C).......C inher. from B which itself is inher. from A.
 * 4) HYBRID .........Mixture of any of the above
 * 5) HIERARCHICAL......      A
 *                          B   C
 *                         D E F G
 **/

class A{
    string name;   //private member
    public:   //by default....attributes/data members are private...can be accessed within class
    int age;
    bool gender;
};