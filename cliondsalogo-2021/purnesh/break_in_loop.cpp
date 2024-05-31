#include<iostream>
using namespace std;

int largestElement(int &a,int &b,int &c);

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    int result  = largestElement(a,b,c);
    cout<<2*result<<endl;
    cout<<3*result<<endl;
    cout<<4*result<<endl;
}

int largestElement(int &a,int &b,int &c){
          if(a>b){
              if(a>c){
                  return a;
              }else{
                  return c;
              }
          }else if(b>c){
              return b;
          }else {
              return c;
          }
}



