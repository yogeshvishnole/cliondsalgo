#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    // string class is a super powerful abstraction over the char array
    // it basically under the hood uses the same char array
/*
 * some imp functions
 *
 * 1. find
 * 2. substr(start,length)
 * 3. size()
 * 4. getline(cin,str)
 * 5. to_string(number)
 * 6. push_back
 * overload + += etc
 * */

    string s = "abc";
    cout<<s<<endl;

    string *sp = new string;
    *sp = "mno";
    cout<<sp<<endl;
    cout<<*sp<<endl;

    vector<string> v;
    v.push_back(s);
    v.push_back("hello");

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
        sort(v[i].begin(),v[i].end());
        cout<<v[i]<<endl;
    }

    string s2;
    s2 = "def";
    cout<<s2<<endl;
    string s3;
    //getline(cin, s3);
    // cout<<s3<<endl;

    s3 = "abcabc";
    cout<<s3[1]<<endl;
    s3[0] = 'd';
    cout<<s3<<endl;

    string s4 = "";
    s4 += s3 + s2 + "hello coding";
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<s4.size()<<endl;
    cout<<s4.length()<<endl;

    cout<<s4.substr(3)<<endl;
    string s5 = s4.substr(3,5);
    cout<<s5<<endl;

    cout<<s4.find("abc")<<endl;

    int a = 123;
    string s6 = to_string(a);
    cout<<s6<<endl;
    s6[1] = '4';
    cout<<s6<<endl;

    s6.push_back('5');
    cout<<s6<<endl;

    a = atoi(s6.c_str());
    cout<<a<<endl;
}