#include<iostream>
using namespace std;

int partition(int arr[],int start,int end){
       int pivot = arr[end];
       int pIndex = start;
       for(int i = start;i<end;i++){
           if(arr[i] <= pivot){
               swap(arr[i],arr[pIndex]);
               pIndex++;
           }
       }
       swap(arr[pIndex],arr[end]);
       return pIndex;
}


void quickSort(int arr[],int start,int end){
    if(start<end){
        int partitionIndex = partition(arr,start,end);
        quickSort(arr,start,partitionIndex-1);
        quickSort(arr,partitionIndex+1,end);
    }
}

int main(int argc,char** argv){
    int arr[] = {5,4,3,2,1};
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
    quickSort(arr,0,4);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
}