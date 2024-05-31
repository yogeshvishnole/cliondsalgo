#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

void countSortForRadixSort(int arr[],int n,int div){
    int countArr[10];
    memset(countArr,0,sizeof(countArr));
    for(int i = 0;i<n;i++){
        ++countArr[(arr[i]/div)%10];
    }
    for(int i = 1;i<10;i++){
        countArr[i] = countArr[i] + countArr[i-1];
    }
    int atemp[n];
    for(int i = n-1;i>=0;i--){
        atemp[countArr[(arr[i]/div)%10]-1] = arr[i];
    }
    for(int i = 0;i<n;i++){
        arr[i] = atemp[i];
    }
}

void radixSort(int arr[],int n){
    int max = *max_element(arr,arr+n);

    for(int div = 1;max!=0;div*=10){
        countSortForRadixSort(arr,n,div);
        max = max/10;
    }
}

int main(int argc,char** argv){
    int arr[] = {729,421,902,300,101,200,395,732};
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
    radixSort(arr,8);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
}