#include<iostream>
using namespace std;

int main(){

    // Arithmetic operators + - * / %
    // comparison operators == != < > <= >=

    for(;;){

        int num1;
        int num2;
        int result;
        int userChoice;
        cout<<"Enter two numbers : ";
        cin>>num1>>num2;
        cout<<"For addition press 1"<<endl;
        cout<<"For subtraction press 2"<<endl;
        cout<<"For multiplication press 3"<<endl;
        cout<<"For division press 4"<<endl;
        cin>>userChoice;

        if(userChoice == 1){
            result = num1 + num2;
            cout<<"The result of addition of "<<num1<<" and "<<num2<<" is "<<result<<endl;
        }else if(userChoice == 2){
            result = num1 - num2;
            cout<<"The result of subtraction of "<<num1<<" and "<<num2<<" is "<<result<<endl;

        }else if(userChoice == 3){
            result = num1 * num2;
            cout<<"The result of multiplication of "<<num1<<" and "<<num2<<" is "<<result<<endl;
        }else if(userChoice ==4){
            result = num1 / num2;
            cout<<"The result of division of "<<num1<<" and "<<num2<<" is "<<result<<endl;
        }else{
            cout<<"You enter the wrong choice"<<endl;
        }


    }







}