//
// Created by dell on 31/05/21.
//

#ifndef QUEUE_NODE_H
#define QUEUE_NODE_H
#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node<T>* next;
    Node(T data):data{data}{
        next = NULL;
    }
};

#endif //QUEUE_NODE_H
