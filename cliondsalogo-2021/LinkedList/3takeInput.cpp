#include<iostream>
#include"Node.h"
using namespace std;

template<typename T>
Node<T>* takeInput(){
    Node<T> *head = NULL;
    Node<T> *tail = NULL;
    T data;
    cin>>data;
    while(data!=-1){
        Node<T> *temp = new Node<T>(data);
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            tail->next = temp;
            tail = temp;
        }
        cin>>data;
    }
    return head;
}

template<typename T>
Node<T>* takeInputReverse(){
    Node<T>* head = NULL;
    Node<T>* tail = NULL;
    T data;
    cin>>data;
    while(data != -1){

        Node<T>* temp = new Node<T>(data);
        if(tail == NULL){
            head = temp;
            tail = temp;
        }else{
            temp->next = head;
            head = temp;
        }
        cin>>data;
    }
    return head;
}


int main(int argc,char** argv){
    cout<<"Enter the link list  : "<<endl;
    Node<int> *head = takeInput<int>();
    head = mergeSortLL(head);
    print(head);
}