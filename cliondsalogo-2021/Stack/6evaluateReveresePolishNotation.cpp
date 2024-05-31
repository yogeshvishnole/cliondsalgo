#include<iostream>
#include<vector>
#include<stack>
using namespace std;

bool isOperator(string s){
    if(s == "*" || s == "/" || s == "+" || s=="-"){
        return true;
    }
    return false;
}

string doOperation(string operand1,string operand2,string operator1){
    int num1 = atoi(operand1.c_str());
    int num2 = atoi(operand2.c_str());
    if(operator1 == "+"){
        return to_string(num1 + num2);
    }
    if(operator1 == "-"){
        return to_string(num1-num2);
    }
    if(operator1 =="/"){
        return to_string(num1/num2);
    }
    if(operator1 == "*"){
        return to_string(num1*num2);
    }
    return "";
}

int evalRPN(vector<string>& tokens) {
    stack<string> st;
    for(int  i = 0;i<tokens.size();i++){
        if(!isOperator(tokens[i])){
            st.push(tokens[i]);
        }else{
            string operand2  = st.top();
            st.pop();
            string operand1 = st.top();
            st.pop();
            string result = doOperation(operand1,operand2,tokens[i]);
            st.push(result);
        }
    }
    return atoi(st.top().c_str());
}

int main(int argc,char** argv){
    vector<string> str{"20","3","4","+","*"};
    int ans = evalRPN(str);
    cout<<ans<<"\n";
}