#include <iostream>
#include<queue>
#include"1structureOfBinaryTree.h"
using namespace std;

template<typename T>
void printRecursively(BTNode<T> *root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" : "<<(root->left != NULL ? to_string(root->left->data) : "NULL")<<" , "<<(root->right != NULL ? to_string(root->right->data) : "NULL")<<" "<<"\n";
    printRecursively<T>(root->left);
    printRecursively<T>(root->right);
}

template<typename T>
BTNode<T>* takeInputRecursive(){
    T data;
    cin>>data;
    if(data == -1) return NULL;
    BTNode<T>* root = new BTNode<T>(data);
    cout<<"Enter the left child of "<<root->data<<" ";
    root->left = takeInputRecursive<T>();
    cout<<"Enter the right child of "<<root->data<<" ";
    root->right = takeInputRecursive<T>();
    return root;

}

template<typename T>
BTNode<T>* takeInputLevelWise(){
    T data;
    cout<<"Enter the root node : ";
    cin>>data;
    BTNode<T>* root = new BTNode<T>(data);
    queue<BTNode<T>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<T>* currNode = q.front();
        q.pop();
        cout<<"Enter the left child of "<<currNode->data<<" : ";
        T leftChild;
        cin>>leftChild;
        if(leftChild != 0){
            BTNode<T>* temp = new BTNode<T>(leftChild);
            currNode->left = temp;
            q.push(temp);
        }
        cout<<"Enter the right child of "<<currNode->data<<" : ";
        T rightChild;
        cin>>rightChild;
        if(rightChild != 0){
            BTNode<T>* temp = new BTNode<T>(rightChild);
            currNode->right = temp;
            q.push(temp);
        }
    }
    return root;
}

template<typename T>
void levelOrderTraversal(BTNode<T>* root){
    if(root == NULL) return;
    queue<BTNode<T>*> q;
    q.push(root);
    while(!q.empty()){
        BTNode<T>* currNode = q.front();
        q.pop();
        cout<<currNode->data<<" ";
        if(currNode->left){
            q.push(currNode->left);
        }
        if(currNode->right){
            q.push(currNode->right);
        }
    }
}

template<typename T>
int countNodes(BTNode<T>* root){
    if(root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

template<typename T>
void inorder(BTNode<T>* root){
    if(root == NULL) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

template<typename T>
void preorder(BTNode<T>* root){
    if(root == NULL) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

template<typename T>
void postorder(BTNode<T>* root){
    if(root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

template<typename T>
int maxDepth(BTNode<T>* root){
    if(root == NULL) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

template<typename T>
bool isSymmetric(BTNode<T>* root1,BTNode<T>* root2){
   if(!root1->left || !root2->right){
       if(root1->left == root2->right){
           return true;
       }
       return false;
   }
    bool ans1=false;
    bool ans2=false;

        if(root1->left->data == root2->right->data){
            ans1 = isSymmetric(root1->left,root2->right);
        }else{
            return false;
        }
        if(root1->right->data == root2->left->data ){
            ans2 = isSymmetric(root1->right,root2->left);
        }else{
            return false;
        }


    return ans1 && ans2;

}

template<typename T>
bool findNode(BTNode<T>* root,T key){
    if(root == NULL) return false;
    if(root->data == key) return true;
    return findNode(root->left,key) || findNode(root->right,key);
}

template<typename T>
bool isSymmetric(BTNode<T>* root){
     return isSymmetric(root,root);
}

template<typename T>
T minValue(BTNode<T>* root){
    if(root == NULL) return INT32_MAX;
    int minV = root->data;
    int minLeft = minValue(root->left);
    int minRight = minValue(root->right);
    return min(minV,min(minLeft,minRight));
}

template<typename T>
T maxValue(BTNode<T>* root){
    if(root == NULL) return INT32_MIN;
    int maxV = root->data;
    int maxLeft = maxValue(root->left);
    int maxRight = maxValue(root->right);
    return max(maxV,max(maxLeft,maxRight));
}

template<typename T>
int countLeafNodes(BTNode<T>* root){
    if(root == NULL) return 0;
    if(!root->left && !root->right) return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

template<typename T>
BTNode<T>* buildTree(vector<int>& preorder,vector<int>& inorder,int preStart,int preEnd,int inStart,int inEnd){
    if((preStart>preEnd) || (inStart>inEnd)) return NULL;
    if(preStart == preEnd){
        BTNode<T>* root = new BTNode<T>(preorder[preEnd]);
        root->left = NULL;
        root->right = NULL;
        return root;
    }
    BTNode<T>* root = new BTNode<T>(preorder[preStart]);
    int i = 0;
    while(inorder[i] != preorder[preStart]){
        i++;
    }
    int leftInStart = inStart;
    int leftInEnd = i-1;
    int leftPreStart = preStart+1;
    int leftPreEnd = leftPreStart+(leftInEnd-leftInStart);
    int rightPreStart = leftPreEnd+1;
    int rightPreEnd = preEnd;
    int rightInStart = i+1;
    int rightInEnd = inEnd;
    root->left = buildTree<T>(preorder,inorder,leftPreStart,leftPreEnd,leftInStart,leftInEnd);
    root->right = buildTree<T>(preorder,inorder,rightPreStart,rightPreEnd,rightInStart,rightInEnd);
    return root;
}

template<typename T>
BTNode<T>* buildInPostTree(vector<int>& inorder, vector<int>& postorder,int postStart,int postEnd,int inStart,int inEnd){
    if((postStart>postEnd)||(inStart>inEnd)) return NULL;
    if(postStart==postEnd){
        BTNode<T>* root = new BTNode<T>(postorder[postEnd]);
        root->left =NULL;
        root->right =NULL;
        return root;
    }
    int i = inStart;
    while(inorder[i]!=postorder[postEnd]){
        i++;
    }
    BTNode<T>* root = new BTNode<T>(postorder[postEnd]);
    int leftInStart = inStart;
    int leftInEnd = i-1;
    int leftPostStart = postStart;
    int leftPostEnd =leftPostStart+(leftInEnd-leftInStart);
    int rightInStart= i+1;
    int rightInEnd = inEnd;
    int rightPostStart = leftPostEnd+1;
    int rightPostEnd = postEnd-1;
    root->left = buildInPostTree<T>(inorder,postorder,leftPostStart,leftPostEnd,leftInStart,leftInEnd);
    root->right = buildInPostTree<T>(inorder,postorder,rightPostStart,rightPostEnd,rightInStart,rightInEnd);
    return root;
}
template<typename T>
BTNode<T>* buildInPostTree(vector<int>& inorder, vector<int>& postorder) {
    return buildInPostTree<T>(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1);
}

template<typename T>
int diameter(BTNode<T>* root){
    if(root == NULL) return 0;
    return max(maxDepth(root->left)+maxDepth(root->right),max(diameter(root->left),diameter(root->right)));

}

int main() {
//    BTNode<int>* root = new BTNode<int>(1);
//    BTNode<int>* n1 = new BTNode<int>(2);
//    BTNode<int>* n2 = new BTNode<int>(3);
//    root->left = n1;
//    root->right = n2;
//    1 2 3 5 6 7 8 0 0 0 0 0 0 0 0
//    1 2 3 4 5 6 7 0 0 0 0 8 9 0 0 0 0 0 0
//    1 2 3 4 5 6 0 0 0 0 0 0 0
// symmetric tree 1 2 2 3 4 4 3 0 0 0 0 0 0 0 0
// one more tree --> 1 2 3 5 6 0 0 7 0 0 8 9 0 0 10 0 0 0 0
    BTNode<int>* root = takeInputLevelWise<int>();
    cout<<"\n";
    cout<<"Diameter "<<diameter(root)<<"\n";

}
