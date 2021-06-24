#include<iostream>
using namespace std;

// find first occurence of the target element
int getOccurence(int arr[],int n,int target,bool isFirst=true){
    int start = 0;
    int end = n-1;

    int ans = -1;
    while(start<=end){
        int mid = start - (start-end)/2;
        if(arr[mid] == target){
            ans=mid;
            if(isFirst){
                end=mid-1;
            }else{
                start = mid+1;
            }

        }else if(arr[mid] < target){
            start = mid+1;
        }else{
            end = mid-1;
        }
    }
    return ans;
}

bool binarySearchInRotatedArray(int arr[],int n,int key){
    int start = 0;
    int end = n-1;

    while(start<=end){
        int mid = start - (start - end)/2;
        if(arr[mid] == key){
            return true;
        }
        if(arr[mid] >= arr[start]){
            if(key>=arr[start] && key<=arr[mid]){
                end = mid-1;
            }else{
                start = mid+1;
            }
        }else if(arr[mid] < arr[end]){
            if(key>=arr[mid] && key<=arr[end]){
                start = mid+1;
            }else{
                end=mid-1;
            }
        }
    }
    return false;
}

int main(int argc,char** argv){
     int arr[] = {3,4,5,1,2};
//     cout<<"First Occurence : "<<getOccurence(arr,6,8)<<" ";
//     cout<<"Last occurence : "<<getOccurence(arr,6,8,false);
cout<<boolalpha<<binarySearchInRotatedArray(arr,5,9)<<endl;
}