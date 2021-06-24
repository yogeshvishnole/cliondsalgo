#include<iostream>
using namespace std;

bool checkPalin(int arr[],int i,int j){
    if(i>=j) return true;
    if(arr[i] != arr[j]) return false;
    return checkPalin(arr,i+1,j-1);
}

int main(int argc,char** argv){
    int arr[] = {1,3,3,3};
    cout<<boolalpha<<checkPalin(arr,0,3);
}