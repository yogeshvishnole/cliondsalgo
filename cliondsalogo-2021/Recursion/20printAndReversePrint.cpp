#include<iostream>
using namespace std;

void print(char arr[]){
    if(arr[0] == '\0')  return;
    cout<<arr[0]<<" ";
    print(arr+1);
}

void reverse_print(char arr[]){
    if(arr[0] == '\0') return;
    reverse_print(arr+1);
    cout<<arr[0]<<" ";
}

int main(int argc,char** argv){
    char arr[] = "abc";
    print("abc");
    cout<<"\n";
    reverse_print("abc");
}