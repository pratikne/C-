//https://www.geeksforgeeks.org/difference-between-malloc-and-calloc-with-examples/
//malloc vs calloc

#include <iostream>
using namespace std;

int main(){

    /** C style **/

    int* i = (int*)malloc(sizeof(int)); //1 int
    int* ia = (int*)malloc(sizeof(int) * 10); //10 int so int array
    //malloc garbage value, calloc assigns 0, also it demands 2 parameter

    // Both of these allocate the same number of bytes,
    // which is the amount of bytes that is required to
    // store 5 int values.
 
    // The memory allocated by calloc will be
    // zero-initialized, but the memory allocated with
    // malloc will be uninitialized so reading it would be
    // undefined behavior.
    int* allocated_with_malloc = (int*)malloc(5 * sizeof(int));
    int* allocated_with_calloc = (int*)calloc(5, sizeof(int));
 
    // As you can see, all of the values are initialized to
    // zero.
    printf("Values of allocated_with_calloc: ");
    for (size_t i = 0; i < 5; ++i) {
        printf("%d ", allocated_with_calloc[i]);
    }
    putchar('\n');
 
    // This malloc requests 1 terabyte of dynamic memory,
    // which is unavailable in this case, and so the
    // allocation fails and returns NULL.
    int* failed_malloc = (int*)malloc(1000000000000);
    if (failed_malloc == NULL) {
        printf("The allocation failed, the value of "
               "failed_malloc is: %p",
               (void*)failed_malloc);
    }
 
    // Remember to always free dynamically allocated memory.
    free(allocated_with_malloc);
    free(allocated_with_calloc);

    /** C++ style **/

    int* p = new int(10); //create a pointer pointing to an int having value 10 in it
    //int *parr = new int[10]; //create a pointer pointing to an array of int having size 10 and parr pointing to first element
    int* parr = new(nothrow) int[10]{0};
    if(!p){
        cout << "Memory allocation failed\n";
    }
    //all elements storing 0 in them 
    cout << "\n New Array " << endl;
    for (int i = 0; i < 10; i++){
        cout << *(parr+i) << endl;
    }
    cout << "END" <<endl;
    delete p;
    //delete p; //runtime error
    p = NULL;
    delete p; //Now works fine
    delete[] parr;
    /**
     *      1     2     3     4    5
     *    x[0]  x[1]  x[2]  x[3]  x[4]  <----x
     *      p   p+1   p+2   p+3   p+4   <----ptr storing address of x
     *                                       int* p = x;
     *                                       x = p //Error..Compilation error
     * 
     *  *(x+i) is same as x[i]
     *   (x+i) is same as &x[i]
     * 
     *  
     */

    int x[5] = {1,2,3,4,5};
    int* ptr;
    ptr = x; // x is equivalent to &x[0] 
    ptr = &x[0]; // same as above
    cout << *ptr << endl; // 1
    cout << *(ptr+1) << endl; // points to second element - 2


    int B[2][3] = {};//2D array
    /**
     * B[0]
     * B[1]
     * both are 1D array
     * 
     * int *p = B //Error
     * int *p[3] = B //Fine
     */

    return 0;
}