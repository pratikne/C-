
#include<bits/stdc++.h>
using namespace std;


int main()
{

int num;
cout << "Enter a number : ";
cin>>num;
//To check if number is even or odd
//even number xor with 1 increments the num by 1
//odd number xor with 1 decrements the num by 1
if((num xor 1) == (num+1))
    cout<<"EVEN";
else
    cout<<"ODD"; 

//To check if number is even or odd
//even number AND 1 gives 0
//odd number AND 1 gives 1
if((num & 1) == 0)
    cout<<"EVEN";
else
    cout<<"ODD";

cout<<endl;
//Below multiplies the number by 8..we can easily multiply the number with any factor of 2
//But note..let say for 15...we have to multiply by 16(i.e LS by 4) and then subtract it by 1*n.
cout<<(num << 3)<<endl;


//In general
//Multiply by 2 is eq to left shift by 1   <<1
//Divide by 2 is eq to right shift by 1    >>1
//Remainder of 2 is eq to AND with 1

/**
 * #define INT_BITS 32
 * 
 
return (n | (1 << (k - 1)));            /Set a bit
return (n & (~(1 << (k - 1))));         /Reset a bit
return (n ^ (1 << (k - 1)));            /Toggle a bit
return (n << d)|(n >> (INT_BITS - d));  /left rotate bits by d position
return (n >> d)|(n << (INT_BITS - d));  /right rotate bits by d position

*/

bitset<8> b(num);
//Above uses bitset class of C++ to store 8 bit binary rep. of any num in b .
cout<<"Binary ::: "<<b<<endl;

return 0;
}