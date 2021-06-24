#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void countSort(int arr[],int n){
    int max = *max_element(arr,arr+n);
    int countArr[max+1];
    memset(countArr,0,sizeof (countArr));

    for(int i = 0;i<n;i++){
        ++countArr[arr[i]];
    }

    for(int i = 1;i<=max;i++){
        countArr[i] = countArr[i] + countArr[i-1];
    }

    int tempSolArr[n];

    for(int i = n-1;i>=0;i--){
        tempSolArr[--countArr[arr[i]]] = arr[i];

    }

    for(int i = 0;i<n;i++){
        arr[i] = tempSolArr[i];
    }

}

int main(int argc,char** argv){

    int arr[] = {2,1,1,0,2,5,4,0,2,8,7,7,9,2,0,1,9};
     for(int i:arr){
         cout<<i<<" ";
     }
     cout<<"\n";
    countSort(arr,17);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";

}
