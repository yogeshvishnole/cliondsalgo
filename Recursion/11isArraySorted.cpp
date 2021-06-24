#include<iostream>
using namespace std;

bool isArraySorted(int arr[] , int n){
    if(n==1) return true;
    bool smallAns = isArraySorted(arr,n-1);
    if(smallAns){
        if(arr[n-2] <= arr[n-1]){
            return true;
        }else{
            return false;
        }
    }
    else{
        return smallAns;
    }
}

int main(int argc,char** argv){
     int n;
     cin>>n;
     int arr[n];
     for(int i = 0;i<n;i++){
         cin>>arr[i];
     }
     cout<<std::boolalpha<<isArraySorted(arr,n)<<endl;

}