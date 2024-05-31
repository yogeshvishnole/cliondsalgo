#include<iostream>
using namespace std;

void removeConsDup(char arr[]){
    if(arr[1] == '\0') return;

    if(arr[0] != arr[1]){
        removeConsDup(arr+1);
    }else{
        for(char *p = arr;*p != '\0';p++){
            *p = *(p+1);
        }
        removeConsDup(arr);
    }

}

int main(int argc,char** argv){
    char arr[] = "abad";
    cout<<arr<<endl;
    removeConsDup(arr);
    cout<<arr<<endl;
}