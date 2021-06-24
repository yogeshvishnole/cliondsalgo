#ifndef PRIORITY_QUEUE_PRIORITYQUEUE_H
#define PRIORITY_QUEUE_PRIORITYQUEUE_H

#include<iostream>
#include<vector>
using namespace std;

class PriorityQueue{
    vector<int> pqContainer;
public:
    PriorityQueue(){}
    int getSize(){
        return pqContainer.size();
    }
    bool isEmpty(){
        return pqContainer.size() == 0;
    }
    int getMin(){
        if(isEmpty()){
            return 0;
        }
        return pqContainer[0];
    }
    void insert(int data){
        pqContainer.push_back(data);
        int childIndex = pqContainer.size()-1;
        int parentIndex = (childIndex-1)/2;
        while(parentIndex>=0){
            if(pqContainer[parentIndex] <= pqContainer[childIndex]){
                break;
            }
            swap(pqContainer[parentIndex],pqContainer[childIndex]);
            childIndex = parentIndex;
            parentIndex = (childIndex-1)/2;
        }
    }
    int removeMin(){
        if(isEmpty()) return 0;
        int ans = pqContainer[0];
        int lastValidIndex = pqContainer.size()-1;
        swap(pqContainer[0],pqContainer[lastValidIndex]);
        pqContainer.pop_back();
        lastValidIndex--;
        int pi = 0;
        while(true){
           int lci = 2*pi+1;
           int rci = lci+1;
           int min = pi;
           if(lci<=lastValidIndex && pqContainer[lci] < pqContainer[min]){
               min = lci;
           }
           if(rci <= lastValidIndex && pqContainer[rci] < pqContainer[min]){
               min = rci;
           }
           if(min == pi){
               break;
           }
           swap(pqContainer[pi],pqContainer[min]);
           pi = min;
        }
        return ans;
    }
};

#endif //PRIORITY_QUEUE_PRIORITYQUEUE_H
