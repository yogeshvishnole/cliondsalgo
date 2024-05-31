#ifndef PRIORITY_QUEUE_HEAP_SORT_H
#define PRIORITY_QUEUE_HEAP_SORT_H
#include<iostream>
using namespace std;

void heapSort(vector<int> &v){
    // heap construction
    for(int i = 1;i<v.size();i++){
        int ci = i;
        while(ci>0){
            int pi = (ci-1)/2;
            if(v[pi]<v[ci]){
                swap(v[pi],v[ci]);
            }else{
                break;
            }
            ci = pi;
        }
    }

    // continuous removal from heap
    for(int i = v.size()-1;i>0;i--){
        swap(v[0],v[i]);
        int pi = 0;
        while(true){
            int lci = 2*pi +1;
            int rci = lci +1;
            int max = pi;
            if(lci<i && v[lci] > v[max]){
                max = lci;
            }
            if(rci<i && v[rci]>v[max]){
                max= rci;
            }
            if(max == pi){
                break;
            }
            swap(v[max],v[pi]);
            pi=max;
        }
    }

}

#endif //PRIORITY_QUEUE_HEAP_SORT_H
