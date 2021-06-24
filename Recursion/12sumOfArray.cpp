#include<iostream>
using namespace std;

int sumOfArray(int arr[],int n){
    if(n == 1) return arr[0];
    int smallAns = sumOfArray(arr,n-1);
    return smallAns+arr[n-1];
}

int sumOfArray2(int arr[],int n){
    if(n==1) return arr[n-1];
    int smallAns = sumOfArray2(arr+1,n-1);
    return smallAns + arr[0];
}

int main(int argc,char** argv){
    int arr[5] = {1,2,3,4,5};
    cout<<sumOfArray2(arr,5);
}