
#ifndef BINARYSEARCHTREE_BSTCLASS_H
#define BINARYSEARCHTREE_BSTCLASS_H

#include<iostream>
#include<queue>
using namespace std;

template<typename T>
class BTNode{
public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;
    BTNode(T data):data{data}{
        left = NULL;
        right = NULL;
    }
    ~BTNode(){
        delete left;
        delete right;
    }


};

typedef pair<BTNode<int>*,BTNode<int>*> nodepair;

class BST{
    BTNode<int>* root = NULL;
    bool search(int data,BTNode<int>* root){
        while(root!=NULL){
            if(root->data == data){
                return true;
            }else if(root->data<data){
                root = root->right;
            }else{
                root = root->left;
            }
        }
        return root;
    }
    BTNode<int>* insert(int data,BTNode<int>* root){
        if(root == NULL) {
            root = new BTNode<int>(data);
            root->left = NULL;
            root->right = NULL;
            return root;
        }
        if(data<root->data){
            root->left = insert(data,root->left);
        }else if(data>root->data){
            root->right = insert(data,root->right);
        }else{
            return NULL;
        }
        return root;
    }

    BTNode<int>* deleteNode(BTNode<int>* root,int data){
          if(root == NULL) return NULL;
          if(root->data == data){
              if(root->left != NULL && root->right != NULL){
                     BTNode<int> * rightMin = findMinNodeInBST(root->right);
                     int rightMinData = rightMin->data;
                     root->data = rightMinData;
                     root->right = deleteNode(root->right,rightMinData);
              }else if(root->left == NULL && root->right == NULL){
                  delete root;
                  return NULL;
              }else if(root->left == NULL || root->right == NULL){
                  if(root->left){
                        BTNode<int>* temp = root->left;
                        root->left = NULL;
                        delete root;
                        return temp;
                  }
                  if(root->right){
                      BTNode<int>* temp = root->right;
                      root->right = NULL;
                      delete root;
                      return temp;
                  }
              }
          }else if(root->data<data){
             root->right = deleteNode(root->right,data);
          }else if(root->data>data){
              root->left =  deleteNode(root->left,data);
          }
          return root;
    }

    BTNode<int>* findMinNodeInBST(BTNode<int>* root){
        if(root == NULL) return NULL;
        while(root->left != NULL){
            root = root->left;
        }
        return root;
    }

    nodepair bstToSLL(BTNode<int>* root){
        if(root == NULL){
            nodepair p;
            p.first = NULL;
            p.second = NULL;
            return p;
        }
        nodepair pairleft = bstToSLL(root->left);
        nodepair pairright = bstToSLL(root->right);
        if(pairleft.second){
            pairleft.second->right = root;
        }
        root->right = pairright.first;
        nodepair anspair;
        if(pairleft.first){
            anspair.first = pairleft.first;
        }else{
            anspair.first = root;
        }
        if(pairright.second){
            anspair.second = pairright.second;
        }else{
            anspair.second = root;
        }


        return anspair;
    }
public:
//    ~BST(){
//        delete root;
//    }

    void printLL(BTNode<int>* head){
        cout<<"\n";
        while(head != NULL){
            cout<<head->data<<" ";
            head = head->right;
        }

    }

    void bstToSLL(){
        BTNode<int>* ll = bstToSLL(root).first;
        printLL(ll);
    }

     void insert(int data){
        BTNode<int>* tempRoot = insert(data,this->root);
        if(tempRoot){
            this->root = tempRoot;
        }else{
            cout<<"\"\"\"Not valid value\"\"\""<<"\n";
        }
     }


     void printBST(){
         if(root == NULL) {
             cout<<"\"\"\"Given tree is empty\"\"\""<<"\n";
         }
         queue<BTNode<int>*> q;
         q.push(root);
         cout<<"\n"<<"***Below is your BST***"<<"\n";
         while(!q.empty()){
            BTNode<int>* currNode = q.front();
            q.pop();
            cout<<currNode->data<<" : ";
            if(currNode->left){
                cout<<"Left child : "<<currNode->left->data<<" ";
                q.push(currNode->left);
            }else{
                cout<<"No left child ";
            }
             if(currNode->right){
                 cout<<"Right child : "<<currNode->right->data<<" ";
                 q.push(currNode->right);
             }else{
                 cout<<"No right child ";
             }
             cout<<"\n";
         }
     }

      void deleteNode(int data){
        root = deleteNode(root,data);
    }

      bool search(int data){
         return search(data,this->root);
     }


};

#endif //BINARYSEARCHTREE_BSTCLASS_H
