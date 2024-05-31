#include<iostream>
using namespace std;

int countZeroes(int number){

    if(number == 0) return 0;

    int smallAns = countZeroes(number/10);

    int lastDigit = number%10;

    if(lastDigit)
        return smallAns;
    else
        return smallAns + 1;

}

int main(int argc,char** argv){
    while(true){
        int number;
        cin>>number;
        cout<<countZeroes(number)<<endl;
    }
}