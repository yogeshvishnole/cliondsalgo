#include<iostream>
using namespace std;

int charArrLen(char arr[]){
    if(arr[0] == '\0') return 0;
    int smallLen = charArrLen(arr+1);
    return 1+smallLen;
}

int main(int argc,char** argv){
    char arr[] = {'a','b','c'};
    cout<<charArrLen(arr);
}