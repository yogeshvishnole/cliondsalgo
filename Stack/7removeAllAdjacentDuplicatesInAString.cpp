#include<iostream>
#include<stack>
using namespace std;

string removeDuplicates(string s) {
    stack<char> st;

    for(int i =0;i<s.length();i++){
        if(st.empty()){
            st.push(s[i]);
        }else{
            if(st.top() == s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

    }
    string str = "";
    int curStackSize = st.size();
    for(int i = 0;i<curStackSize;i++){
        str+=st.top();
        st.pop();
    }
    int p1 = 0;
    int p2 = str.length()-1;
    while(p1<=p2){
        swap(str[p1],str[p2]);
        p1++;p2--;
    }
    return str;
}

/*
 * The complexity of above approach is
 * Time complexity == O(n)
 * Space complexity == O(n)
 *
 * We can reduce the space complexity of above question using the implace stack;
 * lets write that solution below
 * */

string removeAdjacentImplace(string str){
    int sptr = -1;
    string ans = "";
    for(int i = 0;i<str.length();i++){
        if(sptr == -1 || str[sptr] != str[i]){
            sptr++;
            str[sptr] = str[i];
        }else{
            sptr--;
        }
    }
    for(int i = 0;i<=sptr;i++){
        ans.push_back(str[i]);
    }
    return ans;
}

int main(int argc,char** argv){
    cout<<removeAdjacentImplace("Missisippi")<<"\n";
}