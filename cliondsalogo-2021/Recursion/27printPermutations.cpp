#include<iostream>
using namespace std;

void printPermut(string str,int i){
    if(str[i] == '\0'){
        cout<<str<<endl;
    }
    for(int j = i;j<str.length();j++){
        swap(str[i],str[j]);
        printPermut(str,i+1);
        swap(str[i],str[j]);
    }
}

int main(int argc,char** argv){
    printPermut("abc",0);
}