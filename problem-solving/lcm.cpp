#include<iostream>
using namespace std;

int main(int argc,char **argv){
    cout<<"Enter two numbers : ";
    int a;
    int b;
    cin>>a>>b;
    int mul1;
    int mul2;

    int i = 1;

    while(1){
        mul1 = a*i;
        if(mul1%a == 0 && mul1%b == 0){
            break;
        }
        i++;
    }

    cout<<"\nThe lcm of "<<a<<" and "<<b<<" is "<<mul1<<"\n";
  }


