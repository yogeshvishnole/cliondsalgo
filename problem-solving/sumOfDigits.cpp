#include<iostream>
using namespace std;

int main(){

    int n;
    cin>>n;
    int sum = 0;
    int orig = n;
    while(n != 0){
        int digit = n%10;
        n = n/10;
        sum += digit;
    }

    cout<<"Digit sum is "<<sum;
    getchar();

}
