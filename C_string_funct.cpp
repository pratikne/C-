// CPP program to demonstrate
// strcat
#include <cstring>
#include <iostream>
using namespace std;
int main()
{
    /**STRLEN**/
    int len;
    char array[20] = "fresh2refresh.com";

    len = strlen(array);

    printf("string length  = %d \n", len);

    /**STRCAT**/
    char dest[50] = "This is an";
    char src[50] = " example";

    strcat(dest, src);
    cout << dest;

    /**STRNCAT**/
    char source[] = " fresh2refresh";
    char target[] = "C tutorial";

    printf("\nSource string = %s", source);
    printf("\nTarget string = %s", target);

    strncat(target, source, 5);

    printf("\nTarget string after strncat( ) = %s", target);
    // Source string                       = fresh2refresh
    // Target string                        = C tutorial
    // Target string after strcat( ) = C tutorial fres

    /**STRCPY**/
    char source[] = "fresh2refresh";
    char target[20] = "";
    printf("\nsource string = %s", source);
    printf("\ntarget string = %s", target);
    strcpy(target, source);
    printf("\ntarget string after strcpy( ) = %s", target);

    /**STRNCPY**/
    char source[] = "fresh2refresh";
    char target[20] = "";
    printf("\nsource string = %s", source);
    printf("\ntarget string = %s", target);
    strncpy(target, source, 5);
    printf("\ntarget string after strcpy( ) = %s", target);

    /**STRCMP**/
    char str1[] = "fresh";
    char str2[] = "refresh";
    int i, j, k;
    i = strcmp(str1, "fresh");
    j = strcmp(str1, str2);
    k = strcmp(str1, "f");
    printf("\n%d %d %d", i, j, k);

    /**STRLWR**/
    char str[] = "MODIFY This String To LOwer";
    printf("%s\n", strlwr(str));

    /**STRUPR**/
    char str[] = "Modify This String To Upper";
    printf("%s\n", strupr(str));

    /**STRREV**/
    char name[30] = "Hello";

    printf("String before strrev( ) : %s\n", name);

    printf("String after strrev( )  : %s", strrev(name));

    /**STRCHR**/
    char string[55] = "This is a string for testing";
    char *p;
    p = strchr(string, 'i');

    printf("Character i is found at position %d\n", p - string + 1);
    printf("First occurrence of character \"i\" in \"%s\" is"
           " \"%s\"",
           string, p);

    /**STRRCHR**/
    char string[55] = "This is a string for testing";
    char *p;
    p = strrchr(string, 'i');

    printf("Character i is found at position %d\n", p - string + 1);
    printf("Last occurrence of character \"i\" in \"%s\" is"
           " \"%s\"",
           string, p);

    /**STRTOK**/
    char string[50] = "Test,string1,Test,string2:Test:string3";
    char *p;
    printf("String  \"%s\" is split into tokens:\n", string);
    p = strtok(string, ",:");
    while (p != NULL)
    {
        printf("%s\n", p);
        p = strtok(NULL, ",:");
    }

    // String “Test,string1,Test,string2:Test:string3” is split into tokens:
    // Test
    // string1
    // Test
    // string2
    // Test
    // string3

    return 0;
}