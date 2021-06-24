#include<iostream>
using namespace std;

void replaceCharacter(char arr[],char el,char elToReplace){
    if(arr[0] == '\0') return;
    if(arr[0] == elToReplace){
        arr[0] = el;
    }
    replaceCharacter(arr+1,el,elToReplace);
}

int main(int argc,char** argv){
  char arr[] = "abcdab";
  cout<<arr<<endl;
  replaceCharacter(arr,'x','a');
  cout<<arr<<endl;
}