#include<iostream>
using namespace std;

int stairCase(int N){
    if(N==0 || N==1) return 1;
    if(N<0) return 0;
    return stairCase(N-1) + stairCase(N-2) + stairCase(N-3);
}

int main(int argc,char** argv){
    cout<<stairCase(4)<<endl;
}