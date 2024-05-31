#include<iostream>
#include<vector>
using namespace std;

void  printAllSubsequences(string input,string output){
    if(input.length() == 0) {
        cout<<output<<endl;
         return;
    }
    printAllSubsequences(input.substr(1),output);
    printAllSubsequences(input.substr(1),output + input[0]);
}

void storeAllSubsequences(string input,string output,vector<string> &v){
    if(input.length() == 0){
        v.push_back(output);
        return;
    }
    storeAllSubsequences(input.substr(1),output,v);
    storeAllSubsequences(input.substr(1),output + input[0],v);
}

int main(int argc,char** argv){
    vector<string> v;
    printAllSubsequences("abc","");
    storeAllSubsequences("abc","",v);
    for(string str:v){
        cout<<str<<endl;
    }
}