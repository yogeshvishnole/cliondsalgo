

#ifndef DYNAMICPROGRAMMING_FIB_H
#define DYNAMICPROGRAMMING_FIB_H

#include<iostream>
using namespace std;

int fibExpensive(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return fibExpensive(n-1) + fibExpensive(n-2);
}

int fibEfficient(int n,int *arr){
    if(n == 0)
        return 0;
    if(n ==1)
        return 1;
    if(arr[n] != 0)
        return arr[n];
    int output = fibEfficient(n-1,arr) + fibEfficient(n-2,arr);
    arr[n] = output;
    return output;
}

int fibIterative(int n){
    int x  = 0;
    int y = 1;
    if(n == 0 || n == 1)
        return n;

    for(int i = 2;i<=n;i++){
        int ans = x+y;
        x = y;
        y = ans;
    }
    return y;
}

#endif //DYNAMICPROGRAMMING_FIB_H
