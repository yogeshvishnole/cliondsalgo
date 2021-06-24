//
// Created by dell on 31/05/21.
//

#ifndef STACK_2STACKCLASSUSINGARRAY_H
#define STACK_2STACKCLASSUSINGARRAY_H
#include<iostream>

using namespace std;

template<typename T>
class Stack{
private:
    T *container;
    int capacity = 4;
    int nextIndex;
public:
    Stack(){
        container = new T[capacity];
        nextIndex=0;
    }

    void push(T data){
        if(nextIndex == capacity){
            T* newArr = new T[capacity];
            for(int i = 0;i<capacity;i++){
                newArr[i] = container[i];
            }
            delete []container;
            container = newArr;
            capacity = 2*capacity;
        }
        container[nextIndex] = data;
        nextIndex++;
    }

    void pop(){
        if(nextIndex == 0){
            cout<<"Stack empty"<<"\n";
            return;
        }
        nextIndex--;
    }

    T top(){
        if(nextIndex == 0) return -1;
        return container[nextIndex-1];
    }

    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        return nextIndex == 0;
    }

};

#endif //STACK_2STACKCLASSUSINGARRAY_H
