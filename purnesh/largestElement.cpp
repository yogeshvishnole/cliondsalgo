#include<iostream>
using namespace std;

int main(){

    int arr[6];
    for(int i = 0;i<6;i++){
        cin>>arr[i];
    }

    int largestElement = arr[0];

    for(int i = 1;i<=5;i++){
        if(largestElement<arr[i]){
            largestElement = arr[i];
        }
    }

    cout<<largestElement<<endl;


}
