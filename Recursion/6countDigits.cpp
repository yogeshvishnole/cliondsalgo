#include<iostream>
using namespace std;

int countDigit(int number){
    if(number == 0) return 0;
    int smallAns = countDigit(number/10);
    return 1 + smallAns;
}

int main(int argc,char** argv){

    while(true){
        int number;
        cin>>number;
        cout<<countDigit(number)<<endl;
    }

}