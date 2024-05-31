#include<iostream>
using namespace std;

int main(){

    int n,n1;
    cout<<"enter two numbers"<<endl;
    cin>>n>>n1;
    int i;
    for(i=2;i<n;i++)
    {
        if(n%i==0)
        {
            cout<<"this is not a prime number"<<endl;
            break;
        }
    }

     if(i == n)
    {
        cout<<"this is a prime number";
    }

    for(i=2;i<n1;i++)
    {
        if(n1%i==0)
        {
            cout<<"this is not a prime number"<<endl;
            break;
        }
    }

    if(i == n1)
    {
        cout<<"this is a prime number";
    }


}
