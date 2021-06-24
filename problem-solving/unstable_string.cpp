#include<iostream>
#include<vector>
#include<cstring>
#include<numeric>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        if(s.length() == 1){
            cout<<1<<"\n";
            continue;
        }
        if(s[0] == '?'){
            if(s[1] == '0'){
                s[0] = '1';
            }else if(s[1] == '1'){
                s[0] = '0';
            }else{
                s[0] = 0;
            }
        }
        for(int i = 1;i<s.length();i++){
            if(s[i]=='?'){
                if(s[i-1] == '1'){
                    s[i] = '0';
                }else{
                    s[i] = '1';
                }
            }
        }
        vector<int> v(s.length(),0);
        int count = 1;
        for(int i = 1;i<s.length();i++){
            if(s[i-1] == s[i]){
                v.push_back(count);
                count = 1;
            }else{
                count++;
            }
        }
        v.push_back(count);
        cout<<reduce(v.begin(),v.end(),0);
    }
}