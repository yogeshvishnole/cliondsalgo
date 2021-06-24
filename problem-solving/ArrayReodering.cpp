#include<iostream>
using namespace std;

int gcd(int a ,int b){
    if(a==b){
        return a;
    }
    if(a<b){
        return gcd(a,b-a);
    }else{
        return gcd(b,a-b);
    }
}

int main(){
    int t;
    cin>>t;

    while(t--){
        int sOfA;
        cin>>sOfA;
        int arr[sOfA];
        for(int i = 0;i<sOfA;i++){
            cin>>arr[i];
        }
        int ansCount = 0;
        for(int i = 0;i<sOfA-1;i++){
            for(int j = i+1;j<sOfA;j++){
                 if(gcd(arr[i],2*arr[j]) > 1){
                     ansCount++;
                 }
            }
        }
        cout<<"\nans  : "<<ansCount<<"\n";
    }
}