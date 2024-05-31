#include<iostream>
#include<cmath>
using namespace std;

double gSum(int k){
    if(k == 0) return 1;
    double smallAns = gSum(k-1);
    return smallAns + (1.0/pow(2.0,k));
}

int main(int argc,char** argv){

while(true){
    int k;
    cin>>k;
    cout<<gSum(k)<<endl;
}

}