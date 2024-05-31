#include<iostream>
using namespace std;

/*
 *  Docs
 *
 *  Operator Overloading
 *
 *  In c++ we can make operators to work for user defined classes.
 *  This means c++ has the ability to provide the operators
 *  with a special meaning for a data type. This ability is called as operator
 *  overloading.
 *
 *  Rules of operator overloading --
 *
 *  1. You cannot define new operators
 *  2. You can not redefine the meaning of operators when applied
 *     to built in datatypes.
 *  3. Overloaded operators must either be a nonstatic class member function or a global function.
 *     A global function that needs access to private or protected class members must be declared as
 *     a friend of that class. A global function must take at least one argument that is of class or
 *     enumerated type or that is a reference to a class or enumerated type.
 *
 *     See all the rules from microsoft cpp documentation or on google serach rules of operator overloading.
 *
 *  Which operators cant overloaded
 *
 *  NON REDEFINABLE OPERATORS
Operator	Name
.	Member selection
.*	Pointer-to-member selection
::	Scope resolution
? :	Conditional
#	Preprocessor convert to string
##	Preprocessor concatenate


the operators that can not be overloaded by friend function are as follows

 Assignment operator =
 function call operator ()
 subscriping operator []
 class member access operator ->
 *
 *
 * //  Special type operator overloading
 *
 * Conversion Operator: We can also write conversion operators that can be used to convert
 * one type to another type.
 * */


int main(int argc,char** argv){

}
