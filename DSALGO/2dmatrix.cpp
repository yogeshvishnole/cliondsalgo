//
// Created by dell on 26/04/21.
//
#include<iostream>
using namespace std;

void printArr(int a[][2] ,int m,int n){

    for(int i = 0;i<m;i++){
         for(int j = 0;j<n;j++){
             cout<<a[i][j]<<" ";
         }
         cout<<"\n";
    }


}

int main(){

/*     array = [1,2,3,4,5];
     2d array = [
                          [1,2,3,4],
                          [2,3,4,5],
                          [1,2,4,5]
                ]

    declaration

     int matrix1[5][5];  // data_type var_name[rows][columns]; rows is not must but colums number is must

      intializing and printing row wise and column wise

     //  taking row wise
     for(int i = 0;i,i<5;i++){
         for(int j = 0;j<5;j++){
             cin>>matrix1[i][j];
         }

     }

     // printing column wise
    for(int i = 0;i,i<5;i++){
        for(int j = 0;j<5;j++){
            cout<<matrix1[j][i]<<" ";
        }
        cout<<"\n";

    }*/

//intialize all to zero

int arr1[2][10] = {{0}};

// initializing directly

//int arr[2][]   = {{}};  --> Invalid colums must be there we can leave empty only first one
/*
int arr[][2] = {{1,2},{2,3}};

    printArr(arr,2,2);*/

// how 2d arrays are stored in memory

/*
 * Two ways
 *
 * 1. Row major
 * 2. Column major
 *
 * lets asssume 2d array = {{1,2,3},{4,5,6}}
 *
 * then in row major they are 1 d array as = [1,2,3,4,5,6]
 *
 * in column major as [1,4,2,5,3,6]
 *
 * Modern compilers use Row major
 *
 * formula compilers used for calculating position of a 2d array element in 1d array for row major is
 *
 * a[i][j] = i * C + j
 *
 * as C = column numbers
 *
 * this calculation is done by compiler behind the scenes therefor we not have to worry about it
 * and thats why column number otherwise we get error
 *
 * */


}

