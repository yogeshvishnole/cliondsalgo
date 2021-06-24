#include<iostream>
#include<vector>
using namespace std;

void storeAllPos(int arr[],int n,int el,int i,vector<int> &resultVector){
    if(i==n) return;
    if(arr[i] == el){
        resultVector.push_back(i);
    }
    storeAllPos(arr,n,el,i+1,resultVector);
}

int main(int argc,char**argv){

    int arr[6] = {5,5,6,5,6,7};
    vector<int> resultVector;
    storeAllPos(arr,6,7,0,resultVector);
    for(int i:resultVector){
        cout<<i<<endl;
    }


}

