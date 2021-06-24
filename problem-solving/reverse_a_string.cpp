#include<iostream>
using namespace std;

void reverseStr(string& str){
      int p1 = 0;
      int p2 = str.size() -1;

      while(p1 <= p2){
          swap(str[p1],str[p2]);
          p1++;
          p2--;
      }

}

int main(int argc,char **argv){
    string str;
    string str1;
    getline(cin,str);
    getline(cin,str1);
    cout<<"After reverse\n";
    reverseStr(str);
    reverseStr(str1);
    cout<<str<<"\n";
    cout<<str1<<"\n";
}
