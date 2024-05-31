#include<iostream>
using namespace std;

int sumOfDigits(int number){
    if(number == 0) return 0;
    int smallAns = sumOfDigits(number/10);
    return smallAns + (number%10);
}

int main(int argc,char** argv){

    while(true){

        int number;
        cin>>number;
        cout<<sumOfDigits(number)<<endl;

    }

}