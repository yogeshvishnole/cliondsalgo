#include<iostream>
using namespace std;




int main(){
    int a[100];
    for(int i = 0;i<100;i++){
        a[i] = i+1;
    }



    int sum = 0;

 for(int i = 0;i<100;i++){

     sum += a[i];
 }

 int avg = sum/100;
 cout<<avg;

}