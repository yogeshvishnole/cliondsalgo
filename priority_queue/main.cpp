#include <iostream>
#include<queue>
#include "PriorityQueue.h"
#include "heap_sort.h"
using namespace std;

void kSortedArr(int arr[],int k,int n){
    priority_queue<int> p;
    for(int i = 0;i<k;i++){
        p.push(arr[i]);
    }
    int j = 0;
    for(int i = k;i<n;i++,j++){
        int curMax = p.top();
        p.pop();
        p.push(arr[i]);
        arr[j] = curMax;
    }

    while(!p.empty()){
        arr[j] = p.top();
        p.pop();
    }
}

void printKSmallElements(int arr[],int k,int n){
    priority_queue<int> p;
    for(int i = 0;i<k;i++){
        p.push(arr[i]);
    }
    for(int i = k;i<n;i++){
        int mayBeBig = p.top();
        if(arr[i] < mayBeBig){
            p.pop();
            p.push(arr[i]);
        }
    }
    while(!p.empty()){
        cout<<p.top()<<" ";
        p.pop();
    }
}

int main() {

//    PriorityQueue p;
//    p.insert(100);
//    p.insert(10);
//    p.insert(15);
//    p.insert(4);
//    p.insert(17);
//    p.insert(21);
//    p.insert(67);
//    cout<<"Size : "<<p.getSize()<<"\n";
////    cout<<"Min : "<<p.getMin()<<"\n";
//    while(!p.isEmpty()){
//        cout<<"Min: "<<p.removeMin()<<"\n";
//    }

// inbuilt priority queue implemented using the max-heap

//    priority_queue<int> pq;
//    pq.push(10);
//    pq.push(100);
//    pq.push(20);
//    pq.push(3);
//    cout<<" size  : "<<pq.size()<<"\n";
//    while(!pq.empty()){
//        cout<<"Top : "<<pq.top()<<"\n";
//        pq.pop();
//    }

//vector<int> v{10,0,5,67,1};
//for(int i:v){
//    cout<<i<<" ";
//}
//cout<<"\n";
//    heapSort(v);
//    for(int i:v){
//        cout<<i<<" ";
//    }
//    cout<<"\n";=

int arr[] = {100,3,99,21,37,4,5,9,93,77,12};
    printKSmallElements(arr,4,11);




    return 0;
}
