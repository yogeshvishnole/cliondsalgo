#include <bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n<0) return -1;
    if(n == 0) return 1;
    int smallAns = fact(n-1);
    return n*smallAns;
}

int main(int argc,char** argv){

    // Recursion
    // When a function calls itself is called recuursion

    //  When recursion is used

    // When a problem depend on another problem of same nature with lesser input

    //  eXample n factorial = n * factorial of n-1

    // fact(n) = n * fact(n-1)

    // In recursion we need a base caseto terminate otherwise we get call stack overflow

    // factorial recursion example

    int n;
    cin>>n;

    int ans = fact(n);
    cout<<ans<<endl;

}
