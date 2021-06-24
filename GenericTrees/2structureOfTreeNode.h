
#ifndef GENERICTREES_2STRUCTUREOFTREENODE_H
#define GENERICTREES_2STRUCTUREOFTREENODE_H
#include<iostream>
#include<vector>
using namespace std;

/*
 * Vector is best choice for storing childrens of a node in tree
 * Array has fiexed size we have to inilialize with large memory if trreee des not have that much of
 * children then our memory get wasted.
 * If we store in linked list for getting nth children we have to traverse n nodes.
 * */

template<typename T>
class TreeNode{
public:
    T data;
    vector<TreeNode<T>*> childrens;
    TreeNode(T data):data{data}{};

    ~TreeNode(){
        for(int i = 0;i<childrens.size();i++){
            delete childrens[i];
        }
    }

};



#endif //GENERICTREES_2STRUCTUREOFTREENODE_H
