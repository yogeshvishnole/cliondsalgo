#include<iostream>
using namespace std;

void shellSort(int arr[],int n){

    for(int gap = n/2;gap>=1;gap = gap/2){
        for(int j = gap;j<n;j++){
            for(int i = j-gap;i>=0;i=i-gap){
                if(arr[i]<arr[i+gap]){
                    break;
                }else{
                    swap(arr[i],arr[i+gap]);
                }
            }

        }
    }


}

int main(int argc,char** argv){
    int arr[] = {729,421,902,300,101,200,395,732};
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
    shellSort(arr,8);
    for(int i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
}