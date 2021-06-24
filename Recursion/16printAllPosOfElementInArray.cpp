#include<iostream>
using namespace std;

void printAllPos(int arr[],int n,int el,int i){
    if(i==n) return;
    if(arr[i] == el){
        cout<<i<<endl;
    }
    printAllPos(arr,n,el,i+1);
}

int main(int argc,char** argv){
    int arr[5] = {5,5,6,5,6};
    printAllPos(arr,5,6,0);
}
