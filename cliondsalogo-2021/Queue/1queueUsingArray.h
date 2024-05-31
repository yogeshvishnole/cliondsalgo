/*
 * What is a queue ?
 *
 * Queue is a abstract data type
 * In queue data can be inserted from back and can only be
 * removed from front.
 *
 *
 *
 * */

#ifndef QUEUE_1QUEUEUSINGARRAY_H
#define QUEUE_1QUEUEUSINGARRAY_H
#include<iostream>
using namespace std;

template<typename T>
class Queue{
T *container;
int frontIndex;
int nextIndex;
int capacity;
int size;
public:
    Queue(){
        container = new T[4];
        frontIndex = -1;
        nextIndex = 0;
        size=0;
    }

    void push(T data){
        if(size == capacity){
            T *newContainer = new T[2*capacity];
            int j = 0;
            for(int i = frontIndex;i<capacity;i++){
                newContainer[j] = container[i];
                j++;
            }
            for(int i = 0;i<frontIndex;i++){
                newContainer[j] = container[i];
                j++;
            }
            frontIndex = 0;
            nextIndex = capacity;
            nextIndex++;
            container = newContainer;
            delete container;
        }
        container[nextIndex] = data;
        nextIndex = (nextIndex+1)%capacity;
        size++;
        if(frontIndex == -1){
            frontIndex++;
        }
    }

    void pop(){
        if(size == 0){
            cout<<"Queue is empty"<<"\n";
            frontIndex=-1;
            nextIndex=0;
            return;
        }
         frontIndex = (frontIndex+1)%capacity;
        size--;
    }

    T front(){
        if(size == 0){
            cout<<"Queue is empty"<<"\n";
            return 0;
        }
        return container[frontIndex];
    }

    int getSize(){
        return size;
    }

    bool empty(){
        return size == 0;
    }

};

#endif //QUEUE_1QUEUEUSINGARRAY_H
