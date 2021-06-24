#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int  flag = 0;
        for(int j = 0;j<n-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                flag = 1;
            }
             if(flag == 0){
                 break;
             }
        }
    }
}

int main(int argc,char** argv){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    bubbleSort(arr,n);
    for(int i:arr){
        cout<<i<<" ";
    }
}
