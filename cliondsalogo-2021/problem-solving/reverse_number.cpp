#include<iostream>
#include<algorithm>
using namespace std;

int reverseNumber(int n){

    string str = to_string(n);
    reverse(str.begin(),str.end());
    return atoi(str.c_str());
}

int main(int argc,char **argv){

    int n;
    cout<<"Enter the number to be reversed : ";
    cin>>n;

    cout<<"The revesed number is : "<<   reverseNumber(n);

}