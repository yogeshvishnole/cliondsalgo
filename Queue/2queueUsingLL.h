
#ifndef QUEUE_2QUEUEUSINGLL_H
#define QUEUE_2QUEUEUSINGLL_H
#include<iostream>
#include"Node.h"
using namespace std;

template<typename T>
class Queue{
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    int size = 0;
public:
    void push(T data){
       Node<T>* temp = new Node<T>(data);
       size++;
       if(head == NULL){
           head = temp;
           tail = temp;
           return;

       }
       tail->next = temp;
       tail  = temp;
    }
    void pop(){
        if(head == NULL){
            cout<<"Queue is empty"<<"\n";
            return;
        }
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }
    T front(){
        if(head == NULL){
            cout<<"Queue is empty"<<"\n";
            return 0;
        }
        return head->data;
    }
    bool empty(){
        return head==NULL;
    }
    int getSize(){
       return size;
    }
};

#endif //QUEUE_2QUEUEUSINGLL_H
