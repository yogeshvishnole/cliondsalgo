#include<iostream>
using namespace std;

void insertionSort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int temp = arr[i+1];
        int j;
        for(j = i;j>=0;j--){
            if(temp<arr[j]){
                arr[j+1] = arr[j];
            }else{
                break;
            }
        }
        arr[j+1] = temp;
    }
}

int main(int argc,char** argv){
    int n;
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    insertionSort(arr,n);
    for(int i:arr){
        cout<<i<<" ";
    }
}