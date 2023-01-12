#include <bits/stdc++.h>
#include <iostream>


using namespace std;

int main()
{

    // Lambda Function
    /**C++ 11 introduced lambda expressions to allow inline functions
     * which can be used for short snippets of code that are not going
     * to be reused and therefore do not require a name
     *
     * auto fun = [](){}
     *
     * [] -> This is the capture list..we can pass & or = there
     *    -> & means all the local variables will be treated as pass by ref within the function(can be modified)
     *    -> = means all the local variables will be treated as pass by value within the function(just read only)
     *
     * () -> This is the parameters list which we pass to the function same as normal function
     *
     * {} -> function body
     *
     * A lambda expression can have more power than an ordinary function by having access to variables from the enclosing scope. We can capture external variables from the enclosing scope in three ways :
      Capture by reference
      Capture by value
      Capture by both (mixed capture)

Syntax used for capturing variables :
      []  : capture nothing
      [&] : capture all external variables by reference
      [=] : capture all external variables by value
      [a, &b] : capture a by value and b by reference
      [=, &b] : capture all by value except b which should be by reference
      [&, b] : capture all by ref except b which should be by value
      [a, b] : a and b by value

A lambda with an empty capture clause [ ] can only access variables which are local to it.
     *
     *
        [ capture clause ] (parameters) -> return-type
        {
            definition of method
        }


     */
    auto fun = [](int x)
    {
        while (x > 0)
            cout << x-- << endl;
    };

    fun(10); // prints 10 to 1

    vector<int> v1 = {3, 1, 7, 9};
    vector<int> v2 = {10, 2, 7, 16, 9};

    //  access v1 and v2 by reference
    auto pushinto = [&](int m) 
    {
        v1.push_back(m);
        v2.push_back(m);
    };

    // it pushes 20 in both v1 and v2
    pushinto(20);

    // access v1 by copy
    [v1]()
    {
        for (auto p = v1.begin(); p != v1.end(); p++)
        {
            cout << *p << " ";
        }
    };

    int N = 5;

    // below snippet find first number greater than N
    // [N]  denotes,   can access only N by value
    vector<int>::iterator p = find_if(v1.begin(), v1.end(), [N](int i)
                                      { return i > N; });

    cout << "First number greater than 5 is : " << *p << endl;

    // function to count numbers greater than or equal to N
    // [=] denotes,   can access all variable
    int count_N = count_if(v1.begin(), v1.end(), [=](int a)
                           { return (a >= N); });

    cout << "The number of elements greater than or equal to 5 is : "
         << count_N << endl;

    return 0;
}