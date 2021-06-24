#include<iostream>
using namespace std;

int multiplyWithoutOperator(int m,int n){

    if(n == 1) return m;

    int smallAns  = multiplyWithoutOperator(m,n-1);

    return smallAns+m;

}

int main(int argc,char** argv){

    while(true){

        int m,n;
        cin>>m>>n;
        cout<<multiplyWithoutOperator(m,n)<<endl;

    }

}