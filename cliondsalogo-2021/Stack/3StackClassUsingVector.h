//
// Created by dell on 31/05/21.
//

#ifndef STACK_3STACKCLASSUSINGVECTOR_H
#define STACK_3STACKCLASSUSINGVECTOR_H
#include<iostream>
#include<vector>
using namespace std;

template<typename T>
class Stack{
private:
    vector<T> container;
    int nextIndex = 0;
public:
    void push(T data){
        container.push_back(data);
        nextIndex++;
    }
    void pop(){
        if(nextIndex == 0){
            cout<<"Stack Empty"<<"\n";
            return;
        }
        container.pop_back();
        nextIndex--;
    }
    int size(){
        return nextIndex;
    }
    int top(){
        if(nextIndex == 0){
            cout<<"Stack Empty"<<"\n";
            return -1;
        }
        return container[nextIndex-1];
    }
    bool isEmpty(){
        return nextIndex==0;
    }
};

#endif //STACK_3STACKCLASSUSINGVECTOR_H
