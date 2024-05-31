#include<iostream>
using namespace std;

int lastIndex(int arr[],int n,int el){
     if(n == 0) return -1;
     int smallAns = lastIndex(arr+1,n-1,el);
     if(smallAns != -1){
         return smallAns+1;
     }else{
         if(arr[0] == el){
             return 0;
         }else{
             return -1;
         }
     }
}


int main(int argc,char** argv){
    int arr[5] = {5,5,6,5,6};
    cout<<lastIndex(arr,5,0);
}