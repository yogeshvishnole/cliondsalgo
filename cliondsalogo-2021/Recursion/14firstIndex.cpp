#include<iostream>
using namespace std;

int firstIndex(int arr[],int n,int el){
    if(n==0) return -1;
    if(arr[0] == el){
        return 0;
    }
    int smallAns = firstIndex(arr+1,n-1,el);
    if(smallAns != -1){
        return smallAns + 1;
    }else{
        return smallAns;
    }

}

int firstIndex2(int arr[],int i,int n,int el){
    if(i == n){
        return -1;
    }
    if(arr[i] == el){return i;}

    return firstIndex2(arr,i+1,n,el);


}


int main(int argc,char** argv){

    int arr[5] = {5,5,6,5,6};
    cout<<firstIndex(arr,5,7)<<endl;
    cout<<firstIndex2(arr,0,5,7)<<endl;
}

