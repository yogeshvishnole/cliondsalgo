#include<iostream>
using namespace std;
#ifndef LINKEDLIST_NODE_H
#define LINKEDLIST_NODE_H

template<typename T>
class Node{
public:
    T data;
    Node<T>* next;

    Node(T data):data{data}{
        next = NULL;
    }
};

template<typename T>
void print(Node<T>* head){
    Node<T>* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

template<typename T>
int llength(Node<T>* head){
    Node<T>* temp = head;
    int length = 0;
    while(temp != NULL){
        length++;
        temp = temp->next;
    }
    return length;
}

template<typename T>
void printIthNode(Node<T>* head,int i){
    Node<T>* temp = head;
    int count = 0;
    while(count<i && temp!=NULL ){
        count++;
        temp = temp->next;
    }
    if(temp){
        cout<<i<<" th node "<<temp->data<<endl;
    }   else{
        cout<<-1<<endl;
    }
}


// Insert ith node bad logic (but working)

//template<typename T>
//Node<T>* insertAtIthNode(Node<T>* head,int i,T data){
//      Node<T>* tempHead = head;
//      Node<T>* tempHeadTrail = NULL;
//      int count = 0;
//      while(count<i && tempHead != NULL){
//          count++;
//          tempHeadTrail = tempHead;
//          tempHead = tempHead->next;
//      }
//      if(tempHead){
//          Node<T>* newNode = new Node<T>(data);
//          if(tempHeadTrail ){
//              tempHeadTrail->next = newNode;
//              newNode->next = tempHead;
//          }else if(count == i){
//              newNode->next = head;
//              head = newNode;
//          }
//      }else{
//          if(tempHeadTrail && count == i){
//              Node<T>* newNode = new Node<T>(data);
//              tempHeadTrail->next = newNode;
//          }
//      }
//      return head;
//}

template<typename T>
Node<T>* insertAtIthNode(Node<T>* head,int i,T data){
    if(i<0){
        return head;
    }
    if(i == 0){
        Node<T>* newNode = new Node<T>(data);
        Node<T>* tempNode = head;
        head = newNode;
        newNode->next = tempNode;
        return head;
    }
    Node<T>* tempHead = head;
    int count = 0;
    while(count<i-1 && tempHead!=NULL){
        count++;
        tempHead = tempHead->next;
    }
    if(tempHead != NULL){
        Node<T>* newNode = new Node<T>(data);
        newNode->next = tempHead->next;
        tempHead->next = newNode;
    }
    return head;
}

// delete ith node of linked  list with memory leaks

template<typename T>
Node<T>* deleteIthNode(Node<T>* head,int i){

    if(i<0){
        return head;
    }

    if(i==0 && head){
        Node<T>* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
    Node<T>* tempHead = head;
    int count = 0;
    while(count<i-1 && tempHead != NULL){
        count++;
        tempHead = tempHead->next;
    }

    if(tempHead && tempHead->next){
        Node<T>* temp = tempHead->next;
        tempHead->next = tempHead->next->next;
        temp->next = NULL;
        delete temp;
    }

    return head;
}

// Length of linked list recursively

template<typename T>
int llengthR(Node<T>* head){
    if(head == NULL) return 0;
    return 1 + llengthR(head->next);
}

template<typename T>
bool searchKeyInL(Node<T>* head,int key){
    Node<T>* tempHead = head;
    while(tempHead != NULL){
        if(tempHead->data  == key){
            return true;
        }
        tempHead = tempHead->next;
    }
    return false;
}

template<typename T>
bool isPresentR(Node<T>* head,int key){
    if(head == NULL) return false;
    if(head->data == key){
         return true;
    }
    return isPresentR(head->next,key);
}

template<typename T>
Node<T>* midElement(Node<T>* head){
    if(!head) return NULL;
    Node<T>* slow = head;
    Node<T>* fast = head->next;
    while(fast && fast->next && slow){
        slow=slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<typename T>
Node<T>* reverseLinkedList(Node<T>* head){
    if(!head) return head;
    if(!head->next) return head;
    Node<T>* prevNode = NULL;
    Node<T>* currNode = head;
    Node<T>* nextNode = head->next;
    while(currNode){
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
        nextNode=nextNode? nextNode->next:NULL;
    }
    return prevNode;
}

//template<typename T>
//Node<T>* deleteKFromEnd(Node<T>* head,int n){
//    int length = llength(head);
//    int indexToDelete = length-n+1;
//    return deleteIthNode(head,indexToDelete-1);
//}


//  delete kth node fro end in single traversal
template<typename T>
Node<T>* deleteKFromEnd(Node<T>* head,int n){
    if(n<=0) return head;
     Node<T>* first = NULL;
     Node<T>* second = head;
     int count = 0;
     int flag = 0;
     while(count<=n ){
         if(second==NULL){
             if(flag == 0){
                 first = head;
             }
             if(flag == 1){
                 first = NULL;
                 return head;
             }
             flag++;
         }else{
             second = second->next;
         }
         count++;
     }
    if(first == head){
        Node<T>* ans = head->next;
        head->next = NULL;
        delete head;
        return ans;
    }
    first = head;
     while(second){
         second = second->next;
         first=first->next;
     }
     Node<T>* toDelete = first->next;
     first->next = first->next->next;
     delete toDelete;
     return head;
}

template<typename T>
Node<T>* mergeTwoSortedLinkedList(Node<T>* &head1,Node<T>* &head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node<T>* head = NULL;
    Node<T>* trailSmall = NULL;
    if(head1->data<=head2->data){
        trailSmall = head1;
        head = head1;
        head1 = head1->next;
    }else{
        trailSmall = head2;
        head = head2;
        head2 = head2->next;
    }
    while(head1 && head2){
        if(head1->data<=head2->data){
              if(trailSmall->next != head1 ){
                  trailSmall->next = head1;
              }
              trailSmall = head1;
              head1 = head1->next;
        }else{
            if(trailSmall->next != head2){
                trailSmall->next = head2;
            }
            trailSmall = head2;
            head2 = head2->next;
        }
    }
    if(head1 && trailSmall){
        trailSmall->next = head1;
        head1 = NULL;
    }
    if(head2 && trailSmall){
        trailSmall->next = head2;
        head2 = NULL;
    }
    return head;
}

template<typename T>
Node<T>* mergeTSLLR(Node<T>* head1,Node<T>* head2){
    if(head1 == NULL) return head2;
    if(head2 == NULL) return head1;
    Node<T>* head  = NULL;
    if(head1->data<=head2->data){
        head=head1;
        head->next = mergeTSLLR(head1->next,head2);
    }else{
        head=head2;
        head->next = mergeTSLLR(head1,head2->next);
    }
    return head;
}

template<typename T>
Node<T>* mergeSortLL(Node<T>* head){
    Node<T>* mid = midElement(head);
    if(!mid || !mid->next ) return mid;
    Node<T>* head1 = mergeSortLL(mid->next);
    mid->next = NULL;
    Node<T>* head2 = mergeSortLL(head);
    Node<T>* sortedHead = mergeTwoSortedLinkedList(head1,head2);
    return sortedHead;
}

#endif
