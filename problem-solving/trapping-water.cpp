/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby,
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
using namespace std;

int trappingWater(int arr[], int n){

    int p1 = 0;

    for(int i = 1;i<n;i++){

        if(arr[i] >= arr[p1]){
            p1++;
        }else{
            break;
        }
    }

    int p2 = n-1;

    for(int i = n-2;i >= 0;i--){

        if(arr[i] >= arr[p2]  ){
            p2++;
        }else{
            break;
        }

    }

    int waterCount = 0;

    int p3 = p1+1;
    int p4 = p2-1;

    while(p1<p2 && p3<p4){

        if(arr[p3] >= arr[p1]){
            p1 = p3;
            p3++;
        }else{
            waterCount += (min(arr[p1],arr[p2]) - arr[p3]);
            p3++;
        }

        if(arr[p4] >= arr[p2]){
            p2 = p4;
            p4--;
        }else{
            waterCount += (min(arr[p1],arr[p2]) - arr[p4]);
            p4--;
        }

    }


    return waterCount;



}

int main()
{
    int arr[7] = {8,8,2,4,5,5,1};
    cout<<trappingWater(arr,7)<<endl;
}