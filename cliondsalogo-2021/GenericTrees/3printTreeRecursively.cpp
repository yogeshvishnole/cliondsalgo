#include <iostream>
#include<queue>
#include"2structureOfTreeNode.h"
using namespace std;

template<typename T>
void printTreeRecursively(TreeNode<T>* root){
    cout<<root->data<<": ";
    for(int i = 0;i<root->childrens.size();i++){
        cout<<root->childrens[i]->data<<" , ";
    }
    cout<<"\n";
    for(int i = 0;i<root->childrens.size();i++){
        printTreeRecursively(root->childrens.at(i));
    }
}

template<typename T>
TreeNode<T>*  takeInputRecursively(){
    T data;
    cin>>data;
    TreeNode<T>* root = new TreeNode<T>(data);
    cout<<"Enter no.of childrens of "<<root->data<<" : ";
    int noOfChild;
    cin>>noOfChild;
    for(int i = 0;i<noOfChild;i++){
        TreeNode<T>* child = takeInputRecursively<T>();
        root->childrens.push_back(child);
    }
    return root;
}

template<typename T>
TreeNode<T>* takeInputLevelWise(){
    cout<<"Enter the root node : ";
    T data;
    cin>>data;
    if(data == -1) return NULL;
    queue<TreeNode<T>*>  q;
    TreeNode<T>* root = new TreeNode<T>(data);
    q.push(root);
    while(!q.empty()){
        TreeNode<T>* node = q.front();
        q.pop();
        cout<<"Enter the no. of children of "<<node->data<<" : ";
        int noOfChild;
        cin>>noOfChild;

        for(int i = 0;i<noOfChild;i++){
            cout<<"Enter the "<<i+1<<"th"<<" children of "<<node->data<<"\n";
            T data;
            cin>>data;
            TreeNode<T>* newNode = new TreeNode<T>(data);
            node->childrens.push_back(newNode);
            q.push(newNode);
        }
    }
    return root;
}


template<typename T>
void  printTreeLevelWise(TreeNode<T>* root){
    if(root == NULL) return;
    queue<TreeNode<T>*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode<T>* currNode = q.front();
        q.pop();
        cout<<currNode->data<<": ";
        for(int i=0;i<currNode->childrens.size();i++){
            cout<<currNode->childrens[i]->data<<" , ";
            q.push(currNode->childrens[i]);
        }
        cout<<"\n";
    }
}

template<typename T>
int countNodes(TreeNode<T>* root){
     if(root == NULL) return 0;
     int count = 1;
     for(int i = 0;i<root->childrens.size();i++){
         count += countNodes(root->childrens[i]);
     }
     return count;
}

template<typename T>
int heightOfTree(TreeNode<T>* root){
    if(root == NULL) return 0;
   int height = 1;
   int maxHeightOfChild = 0;
   for(int i = 0;i<root->childrens.size();i++){
       int heightOfChild = heightOfTree(root->childrens[i]);
       if(heightOfChild>maxHeightOfChild){
           maxHeightOfChild=heightOfChild;
       }
   }
   return height+maxHeightOfChild;
}

template<typename T>
void printAtDepthk(TreeNode<T>* root,int depth,int currdepth = 0){
     if(root == NULL) return;
     if(depth == currdepth){
         cout<<root->data<<" ";
         return;
     }
     for(int i =0;i<root->childrens.size();i++){
         printAtDepthk(root->childrens[i],depth,currdepth+1);
     }
}

template<typename T>
int countLeafNodes(TreeNode<T>* root){
    if(root == NULL) return 0;
    int ans = 0;
    if(root->childrens.size() == 0){
        return 1;
    }
    for(int i = 0;i<root->childrens.size();i++){
        ans += countLeafNodes(root->childrens[i]);
    }
    return ans;
}

template<typename T>
void preorderTraversal(TreeNode<T>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    for(int i = 0;i<root->childrens.size();i++){
        preorderTraversal(root->childrens[i]);
    }
}

template<typename T>
void postOrderTraversal(TreeNode<T>* root){
    if(root == NULL){
        return;
    }
    for(int i = 0;i<root->childrens.size();i++){
        postOrderTraversal(root->childrens[i]);
    }
    cout<<root->data<<" ";
}

template<typename T>
void deleteTree(TreeNode<T>* root){
    for(int i = 0;i<root->childrens.size();i++){
        deleteTree(root->childrens[i]);
    }
    delete root;
}

int main() {
//    TreeNode<int>* root = new TreeNode<int>(1);
//    TreeNode<int>* n11 = new TreeNode<int>(2);
//    TreeNode<int>* n12 = new TreeNode<int>(3);
//    TreeNode<int>* n21 = new TreeNode<int>(5);
//    TreeNode<int>* n22 = new TreeNode<int>(6);
//    TreeNode<int>* n23 = new TreeNode<int>(7);
//    TreeNode<int>* n24 = new TreeNode<int>(8);
//    root->childrens.push_back(n11);
//    root->childrens.push_back(n12);
//    n11->childrens.push_back(n21);
//    n11->childrens.push_back(n22);
//    n12->childrens.push_back(n23);
//    n12->childrens.push_back(n24);
// input
// 1 3 2 3 4 2 5 6 2 7 8 1 9 0 0 0 0 0
  TreeNode<int>* root= takeInputLevelWise<int>();
  cout<<"\n";
    delete root;
  printTreeLevelWise(root);


  postOrderTraversal(root);

}
