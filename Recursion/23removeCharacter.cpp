#include<iostream>
using namespace std;

void replaceCharacter(char arr[],int elToReplace){
    if(arr[0] == '\0') return;
    if(arr[0] == elToReplace){
        for(char* p = arr;*p != '\0';p++){
            *p = *(p+1);
        }
        replaceCharacter(arr,elToReplace);
    }else{
        replaceCharacter(arr+1,elToReplace);
    }
}

int main(int argc,char** argv){
    char arr[] = "abcdab";
    cout<<arr<<endl;
    replaceCharacter(arr,'a');
    cout<<arr<<endl;
}