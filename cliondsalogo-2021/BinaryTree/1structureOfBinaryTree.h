#ifndef BINARYTREE_1STRUCTUREOFBINARYTREE_H
#define BINARYTREE_1STRUCTUREOFBINARYTREE_H

template<typename T>
class BTNode{
public:
    T data;
    BTNode<T>* left;
    BTNode<T>* right;
    BTNode(T data):data{data}{}
    ~BTNode(){
        delete left;
        delete right;
    }
};

#endif //BINARYTREE_1STRUCTUREOFBINARYTREE_H
