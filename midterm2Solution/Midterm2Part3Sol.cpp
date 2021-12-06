#include <iostream>

using namespace std;

int main(){

    // //q1
    // What will be the final value of x?
    // Show the intermediate values of x (from lines 12 and 13)before 
    // we get to the final value.

    // int x = 8;
    // x <<= 2;
    // x |= 16;
    // cout << x;

    // 32, then finally 48 

    /* Question 2
    Suppose that the following member method has been added to
    SomeClass with the intention of overloading the prefix -- operator
    for objects of SomeClass.
    What is the problem in the following code? Briefly describe

    SomeClass& operator--(int i){
        // assume code in here has no errors
    }
    */

    // solution: the method should not take any parameters). 

    /* Question 3
Suppose that the following templated function definition exists somewhere before main.

template <typename T, typename V>
void Fun(T a, V b){
    // assume the function body has been written without any errors
}

Now inside the main function the following line tries to use Fun.

Fun(12, 3.4);

Will this line in main produce any errors? If yes, why so? If no, what will be the values of T and V.

*/

/* Question 4
You encounter the following function somewhere (NOT inside SomeClass) and
you are aware that SomeClass has a private member named x of type double.

What is the relationship between SomeFun and SomeClass given that
the following code has no errors? Give reason for your answer.

void SomeFun(SomeClass obj){
    cout << obj.x;
}
*/

// Function SomeFun is a friend of SomeClass hence it is able to access private members of SomeClass  



    return 0;
}