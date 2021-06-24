#include<bits/stdc++.h>
using namespace std;

int power(int base,int exponent){

    if(exponent == 0) return 1;

    int smallAns = power(base,exponent-1);

    return base*smallAns;
}


int main(int argc,char** argv){

    while(true){

        int base,exponent;
        cin>>base>>exponent;
        cout<<power(base,exponent)<<endl;


    }

}