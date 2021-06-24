#include<iostream>
using namespace std;

void selectionSort(int arr[],int n){
    for(int i = 0;i<n-1;i++){
        int min = arr[i];
        int minIndex = i;
        for(int j = i+1;j<n;j++){
            if(arr[j] < min){
                min = arr[j];
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }
}


int main(int argc,char** argv){

    int n;
    cin>>n;

    int arr[n];
    for(int i = 0;i<n;i++){
        cin>>arr[i];
    }

    selectionSort(arr,n);
    for(int i:arr){
        cout<<i<<" ";
    }


}