#include <iostream>
using namespace std;

template<typename T>
T area(T a,T b){
    T result = a*b;
    return result;
}


int main() {

    //STl standard template library

    // A set of tools available in c++ programming platform
    // Its function helps us in writing code quickly , efficiently  ,and in generic way

    /*
     *  Generic Programming
     *
     *  Data types not specified in implementation , but rather in its use.
     *
     *  It is compile time polymorphism
     *
     *  Because all the variations for the generic class or function all are generated or resolved at compile
     *  time , compile time polymorphsim is better than runtime as it prevents some cpu cycles at run time.
     * */


    // Now example of generic programming in cpp

    //  c++ enables generic programming by means of special constructs calles Templates

    // Example of a generic function  see above

   /*   int res1 = area<int>(5,10);
      double res2 = area<double>(5.5,10.5);

      cout<<res1<<" "<<res2<<"\n";*/

   /*
    * Components of STl
    *
    * 1. containers --> data structures for storing the data
    *
    * 2. Iterators --> THis are pointers helpful in traversal over the containers
    *
    * 3. Algorithms --> This are the utillity generic or non generic functions which are very helpful
    *    they are generally declared in <algorithm>
    *
    *  4. Functors (function objects)
    *     This are classes that overload the () operator to see like functions and maintain state
    *     st::plusetc are example
    *     this are declared in <functional>
    *
    *
    *
    *
    * */


}
