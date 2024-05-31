#include <iostream>
#include"2structureOfTreeNode.h"
using namespace std;

int main() {
    TreeNode<int>* root = new TreeNode<int>(1);
    TreeNode<int>* n1 = new TreeNode<int>(2);
    TreeNode<int>* n2 = new TreeNode<int>(3);
    root->childrens.push_back(n1);
    root->childrens.push_back(n2);
}
