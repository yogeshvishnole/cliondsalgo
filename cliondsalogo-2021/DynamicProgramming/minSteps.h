#ifndef DYNAMICPROGRAMMING_MINSTEPS_H
#define DYNAMICPROGRAMMING_MINSTEPS_H

#include<iostream>
#include<cstring>
using namespace std;

int minStepsExpensive(int n){
    if(n == 1)
        return 0;
    int min1 = INT32_MAX;
    int min2  = INT32_MAX;
    int min3 = INT32_MAX;
    if(n%3 == 0)
        min1 = minStepsExpensive(n/3);
    if(n%2 == 0)
        min2 = minStepsExpensive(n/2);
    min3 = minStepsExpensive(--n);
    return 1 + min(min1 ,min(min2,min3));
}

int minStepsEfficient(int n,int *arr){
    if(n == 1 || n == 0)
        return 0;
    int min1 = INT32_MAX;
    int min2  = INT32_MAX;
    int min3 = INT32_MAX;
    if(arr[n] != -1){
        return arr[n];
    }
    if(n%3 == 0)
        min1 = minStepsEfficient(n/3,arr);
    if(n%2 == 0)
        min2 = minStepsEfficient(n/2,arr);
    min3 = minStepsEfficient(n-1,arr);
    int ans =  1 + min(min1 ,min(min2,min3));
    arr[n] = ans;
    return ans;
}

int minStepsBottomUp(int n){
    int *arr = new int[n+1];
    memset(arr,-1,(sizeof (int)) * (n+1) );
    arr[0] = 0;
    arr[1] = 0;
    for(int i =2;i<=n;i++){
        arr[i] = arr[i-1];
        if(i%2 == 0){
            arr[i] = min(arr[i],arr[i/2]);
        }
        if(i%3 == 0){
            arr[i] = min(arr[i],arr[i/3]);
        }
        arr[i]++;
    }
    int output = arr[n];
    delete []arr;
    return output;
}

#endif //DYNAMICPROGRAMMING_MINSTEPS_H
