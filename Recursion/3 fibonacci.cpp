#include<bits/stdc++.h>
using namespace std;

int fib(int n ){

    //edge case
    if(n<0) return -1;


    // base case
    if(n == 0) return 0;
    if(n == 1) return 1;

    // recursive case
    int smallAns1 = fib(n-1);
    int smallAns2 = fib(n-2);

    // calcculation
    return smallAns1 + smallAns2;


}

int main(int argc,char** argv){
    while(true){

        int n;
        cin>>n;
        cout<<fib(n)<<endl;

    }


}

