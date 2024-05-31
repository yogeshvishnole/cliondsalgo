
#ifndef STACK_NODE_H
#define STACK_NODE_H
#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* next = NULL;
    Node(T data):data{data}{}
};

template<typename T>
int lengthOfLL(Node<T>* head){
    Node<T>* tempHead = head;
    int count = 0;
    while(tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }
    return count;
}


#endif //STACK_NODE_H
