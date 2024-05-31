//
// Created by dell on 31/05/21.
//

#ifndef STACK_4STACKUSINGLINKEDLIST_H
#define STACK_4STACKUSINGLINKEDLIST_H
#include<iostream>
#include"Node.h"
using namespace std;

namespace llstack {


    template<typename T>
    class Stack {
    private:
        Node<T> *head = NULL;
    public:
        void push(T data) {
            Node<T> *newNode = new Node<T>(data);
            newNode->next = head;
            head = newNode;
        }

        void pop() {
            if (!head) {
                cout << "Stack Empty" << "\n";
                return;
            }
            Node<T> *tempNode = head;
            head = head->next;
            tempNode->next = NULL;
            delete tempNode;
        }

        T top() {
            if (!head) return 0;
            return head->data;
        }

        int size() {
            return lengthOfLL(head);
        }

        bool isEmpty() {
            return !head;
        }
    };
}

#endif //STACK_4STACKUSINGLINKEDLIST_H
