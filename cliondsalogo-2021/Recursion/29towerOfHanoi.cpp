#include<iostream>
using namespace std;

void towerOfHanoi(int n,int s,int d,int h){
    if(n>0){
        towerOfHanoi(n-1,s,h,d);
        cout<<"MOve disk from "<<s<<" to "<<d<<" "<<endl;
        towerOfHanoi(n-1,h,d,s);
    }
}

int main(int argc,char** argv){
    towerOfHanoi(3,1,2,3);
}