#include<iostream>
using namespace std;

template<typename T>
class Node{
public:
    T data;
    Node* next;

    Node(T data):data{data}{
        next = NULL;
    }
};

// function for print linkedlist

template<typename T>
void print(Node<T>* head){
    Node<T>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int main(int argc,char** argv){

    Node<char> *n1 = new Node<char>('Y');
    Node<char> *n2 = new Node<char>('o');
    Node<char> *n3 = new Node<char>('g');
    Node<char> *n4 = new Node<char>('e');
    Node<char> *n5 = new Node<char>('s');
    Node<char> *n6 = new Node<char>('h');

    // Create links

    Node<char> *head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;

    print(head);

}