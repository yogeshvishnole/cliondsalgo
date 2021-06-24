#include<iostream>
using namespace std;

bool isPresentInArray(int arr[],int n,int x){
    if(n==1) {
        if(arr[n-1] == x) return true;
        return false;
    }
    bool smallAns = isPresentInArray(arr,n-1,x);

    if(!smallAns){
        if(arr[n-1] == x) return true;
        return false;
    }else {
        return smallAns;
    }
}


int main(int argc,char** argv){

    int arr[6] = {1,2,3,6,7};
    cout<<boolalpha<<isPresentInArray(arr,5,5);
}