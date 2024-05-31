#include<iostream>
using namespace std;

void printUpton(int n){
    if(n == 1) {
        cout<<n<<endl;
        return;
    }
    printUpton(n-1);
    cout<<n<<endl;
}

int main(int argc,char** argv){
    int n = 5;
    printUpton(n);
}