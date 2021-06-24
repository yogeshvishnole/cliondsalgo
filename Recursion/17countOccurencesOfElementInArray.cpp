#include<iostream>
using namespace std;

int countOccurences(int arr[],int n,int el){
    if(n == 0) return 0;
    int smallAns = countOccurences(arr+1,n-1,el);
    if(arr[0] == el){
        return smallAns+1;
    }
    return smallAns;
}

int main(int argc,char** argv){
    int arr[6] = {5,5,6,5,7,6};
    cout<<countOccurences(arr,6,10);
}