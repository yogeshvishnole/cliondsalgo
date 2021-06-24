#include<iostream>
#include<cmath>
using namespace std;

int charToInt(char c){
    return  c - '0';
}

int stringToInt(string str){
    if(str.length() == 0) return 0;
    int smallAns = stringToInt(str.substr(1));
    int ans = smallAns + charToInt(str[0])*pow<int,int>(10,(str.length() -1));
    return ans;
}

int main(int argc,char** argv){
   cout<<stringToInt("12345") + 1<<endl;
}