#include<iostream>
using namespace std;

int main(){
    int a = 3;
    // address of operator = & == unary operator
    cout<<"Address of a is "<<&a<<endl;

    // pointers
    int *b;
    b = &a;
    // derefrerencing
    cout<<*b;
}