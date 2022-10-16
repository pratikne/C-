/**CAST OPERATORS - Forcing one data type to another
 * 
 * A) STATIC_CAST
 * 
 * 1. performs implicit conversions
 * 2. checks for error in compile time
 * 3. char* to int* is allowed in C-style but not with static_cast
 * 4. it also avoids cast from derived to private base pointer
 * 5. use for all upcast (derived to base) but not for downcast (use dynamic_cast there)
 * 6. preferred when converting to void* OR from void*
 * 7. easy to locate
 * 
 * B) DYNAMIC_CAST
 * 
 * 1. checks runtime for error
 * 
 * 
 * C) REINTERPRET_CAST
 * 
 * 1. it can perform dangerous conversions coz it can typecast any pointer to any other
 * 
 * D) CONST_CAST
 * use to cast away the constness of variables
 */

int main(){
    float f = 2.4f;
    int a;

    a = f; //2 (implicit casting of float to int)

    double x = 1.2;
    int xi = (int) x; // explicit casting from double to int

    //static_cast<kisme type me cast karna hai> (kisko cast karna hai)
    int ai = static_cast<int>(f);

    int b = 10;
    void *v = static_cast<void*>(&b);
    int *t = static_cast<int*>(v);
    return 0;
}