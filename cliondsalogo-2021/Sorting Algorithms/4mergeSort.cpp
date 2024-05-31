#include <iostream>
using namespace std;

void merge(int arr[], int start, int mid, int end)
{
    int mx = INT32_MIN;

    for (int i = start; i <= mid; i++)
    {
        mx = max(mx, arr[i]);
    }

    for (int i = mid + 1; i <= end; i++)
    {
        mx = max(mx, arr[i]);
    }

    mx = mx + 1;


    int i = start, j = mid+1, k = start;

    while(i<=mid && j<=end && k<=end){
        int e1 = arr[i]%mx;
        int e2 = arr[j]%mx;
        if(e1<e2){
            arr[k] += e1*mx;
            i++;
            k++;
        }else {
            arr[k] += e2 * mx;
            j++;
            k++;
        }
    }
    while(i<=mid){
       int e  = arr[i]%mx;
       arr[k] += e*mx;
       i++;
       k++;
    }

    while(j<=end){
        int e  = arr[j]%mx;
        arr[k] += e*mx;
        j++;
        k++;
    }
    for(int i = start;i<=mid;i++){
        arr[i] = arr[i]/mx;
    }

    for(int j = mid+1;j<=end;j++){
        arr[j] = arr[j]/mx;
    }
}

void mergeSort(int arr[], int start, int end)
{
    if (start == end) return;
    int mid = start - (start - end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

int main(int argc, char **argv)
{
    int arr[] = {5,4,3,2,1};
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
    mergeSort(arr,0,4);
    for(auto i:arr){
        cout<<i<<" ";
    }
    cout<<"\n";
}