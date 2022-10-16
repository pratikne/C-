#include<stdio.h>

struct empty{};
class emp{};
/**
 * Empty class contains defualt member functions
 * 1 byte is allocated for objects unique address identification 
 */

int main(int argc, char const *argv[])
{
    /* code */
    struct empty e1,e2;
    emp em1,em2;
    printf("Size : [%d]",sizeof(struct empty));  //C struct takes 0 size if defined empty but CPP takes 1 byte of memory..same as Class
    printf("Size : [%d]",sizeof(emp));
    if(&e1 == &e2)
        printf("SAME");
    else
        printf(" NOT SAME");
    if(&em1 == &em2)
        printf("SAME");
    else
        printf(" NOT SAME");
    return 0;
}
