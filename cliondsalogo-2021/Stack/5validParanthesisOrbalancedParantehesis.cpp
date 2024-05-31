#include<iostream>
#include<stack>
using namespace std;

// Problem statement --> given a string with 6 type of characters only that are
/* {}[]()
 * We have to check if given string has balanced number of paranthesis with closing brace of
 * same type
 * */

char giveOpeningBrace(char c){
    switch(c){
        case ']':
            return '[';
        case '}':
            return '{';
        case ')':
            return '(';
        default:
            return '0';
    }
}

bool validParanthesis(string s){
    stack<char> st;
    for(int i = 0;i<s.length();i++){
        if(s[i] == '(' || s[i] == '{' || s[i] == '['){
            st.push(s[i]);
        }else{
            if(!st.empty()){
               if(st.top() != giveOpeningBrace(s[i])){
                   return false;
               }
               st.pop();
            }else{
                return false;
            }
        }
    }
    if(st.empty()){
        return true;
    }
    return false;
}

int main(int argc,char** argv){
    string s = "(){}[]";
    cout<<boolalpha<<validParanthesis(s);
}