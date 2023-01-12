// C++ code to demonstrate tuple, get() and make_pair()
// https://www.geeksforgeeks.org/tuples-in-c/
#include<iostream>
#include<tuple> // for tuple

using namespace std;

int main()
{
    // Declaring tuple
    tuple <char, int, float, string> tupobj;
  
    // Assigning values to tuple using make_tuple()
    tupobj = make_tuple('a', 10, 15.5, "Hello");
    auto tup1 = make_tuple('a', 10, 15.5, "Hello"); //Possible

    // Printing initial tuple values using get()
    cout << "The initial values of tuple are : ";
    cout << get<0>(tupobj) << " " << get<1>(tupobj) << " ";
    cout << get<2>(tupobj) << " " << get<3>(tupobj) << endl;
  
    // Use of get() to change values of tuple
    get<0>(tupobj) = 'b';
    get<2>(tupobj) =  20.5;
  
     // Printing modified tuple values
    cout << "The modified values of tuple are : ";
    cout << get<0>(tupobj) << " " << get<1>(tupobj);
    cout << " " << get<2>(tupobj) << endl;

    cout << tuple_size<decltype(tupobj)>::value << endl;

    int i_val;
    char ch_val;
    float f_val;  
    tuple <int,char,float> tup2(20,'g',17.5);
    //tup1.swap(tup2);
    // Use of tie() without ignore
    tie(i_val,ch_val,f_val) = tup2;

    // Displaying unpacked tuple elements
    // without ignore
    cout << "The unpacked tuple values (without ignore) are : ";
    cout << i_val << " " << ch_val << " " << f_val;
    cout << endl;
      
    // Use of tie() with ignore
    // ignores char value
    tie(i_val,ignore,f_val) = tup2;
      
    // Displaying unpacked tuple elements
    // with ignore
    cout << "The unpacked tuple values (with ignore) are : ";
    cout << i_val  << " " << f_val;
    cout << endl;
  
    return 0;
}