#include<iostream>
#include"2HashClass.h"
using namespace std;

int main(){
    Map<int> ourmap;
    for(int i = 0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        int value = i+1;
        ourmap.insert(key,value);
        cout<<ourmap.getLoadFactor()<<endl;
    }
    cout<<ourmap.size()<<endl;
    ourmap.remove("abc0");
    for(int i = 0;i<10;i++){
        char c = '0' + i;
        string key = "abc";
        key += c;
        cout<<key<<" "<<ourmap.getValue(key)<<"\n";
    }
    cout<<ourmap.size()<<endl;
}