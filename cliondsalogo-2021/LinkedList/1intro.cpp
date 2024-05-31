#include<iostream>
using namespace std;

//  Linked list is a random allocation of data
// it is sequential
// one node keeps the address of next node

template<typename T>
class Node{
public:
    T data;
    Node* next;

    Node(T data):data{data} {
        next = NULL;
    }

};

ostream& operator<<(ostream& output,Node<int>& n){
    output<<n.data;
    return output;
}

int main(int argc,char** argv){

// creating nodes statically
Node<int> n1(1);
Node<int> n2(2);
cout<<n1<<" "<<n2;

// creating the nodes dynamically in heap
Node<int> *n3 = new Node<int>(3);
Node<int> *n4 = new Node<int>(4);
Node<int> *n5 = new Node<int>(5);
// Make links
Node<int>* head = &n1;
n1.next  = &n2;
n2.next = n3;
n3->next = n4;
n4->next = n5;

}