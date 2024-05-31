#include<iostream>

void printIntegerArray(int arr[],int n) {
    for(int i = 0;i<n;i++){
        std::cout<<arr[i]<<" ";
    }
    std::cout<<std::endl;
}


void rearrange(int arr[],int n){

    int temp[n];
    int j = 0;
    for(int i = 0;i<n;i++){
        if(arr[i] >= 0){
            temp[j] = arr[i];
            j++;
        }
    }
    int lastPosIndex = j-1;
    for(int i = 0;i<n;i++){
        if(arr[i]<0){
            temp[j] = arr[i];
            j++;
        }
    }



    int m = 0;
    int l = lastPosIndex + 1;
    int k = 0;

    while(m<=lastPosIndex && l<n){

        if(k%2 == 0){
            arr[k] = temp[m];
            m++;
            k++;
        }else{
            arr[k] = temp[l];
            l++;
            k++;
        }

    }

std::cout<<"m = "<<m<<" Last = "<<lastPosIndex<<" n = "<<n<<std::endl;
    while(m<=lastPosIndex && k<n){
        arr[k] = temp[m];
        m++;
        k++;
    }

//    std::cout<<"Temparray : "<<std::endl;
//    printIntegerArray(temp,5);


    while(l<n && k<n){
        arr[k] = temp[l];
        l++;
    }

}


int main(){

    int arr[] = {4,5,6,7,-1};
    int n = 5;

    std::cout<<"Before rearrange : "<<std::endl;
    printIntegerArray(arr,n);

    //rearrange
    rearrange(arr,n);

    std::cout<<"After rearrange : "<<std::endl;
    printIntegerArray(arr,n);

}

