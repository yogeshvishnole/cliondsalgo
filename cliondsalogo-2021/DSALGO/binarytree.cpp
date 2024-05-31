#include<iostream>
#include <queue>

using namespace std;

template<typename T>
class BtNode{
public:
    T data;
    BtNode* left;
    BtNode* right;

    BtNode(T data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

template<typename T>
BtNode<T>* takeBinaryTree(){
    int rootData;
    cout<<"Enter the root data : ";
    cin>>rootData;
    BtNode<T>* root = new BtNode<T>(rootData);

    queue<BtNode<T>*> treeQueue;
    treeQueue.push(root);

    while(!treeQueue.empty()){

        BtNode<T>* temp = treeQueue.front();
        treeQueue.pop();
        cout<<"Enter left child of "<<temp->data<<" ";
        int leftChildData;
        cin>>leftChildData;
        if(leftChildData != -1){
            BtNode<T>* leftChild = new BtNode<T>(leftChildData);
            temp->left = leftChild;
            treeQueue.push(leftChild);
        }
        cout<<"Enter right child of "<<temp->data<<" ";
        int rightChildData;
        cin>>rightChildData;
        if(rightChildData != -1){
            BtNode<T>* rightChild = new BtNode<T>(rightChildData);
            temp->right = rightChild;
            treeQueue.push(rightChild);
        }

    }

    return root;

}

template<typename T>
void printBinaryTree(BtNode<T>* root){

    queue<BtNode<T>*> treePrintQueue;
    treePrintQueue.push(root);
    while(!treePrintQueue.empty()){
        BtNode<T>* curEle = treePrintQueue.front();
        cout<<curEle->data<<" ";
        treePrintQueue.pop();
        if(curEle->left){
            treePrintQueue.push(curEle->left);
        }
        if(curEle->right){
            treePrintQueue.push(curEle->right);
        }
    }

}

template<typename T>
void printRecursivePreorder(BtNode<T>* root){
    if(root == NULL){
        return
    }
}

int main(){

    BtNode<int>* root = takeBinaryTree<int>();
    printBinaryTree<int>(root);

}
