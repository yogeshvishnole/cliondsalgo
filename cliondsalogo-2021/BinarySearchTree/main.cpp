#include<iostream>
#include "BSTClass.h"
using namespace std;

template<typename T>
void printVector(const vector<T>& v){
    cout<<"\n"<<"print vector of size "<<v.size()<<"\n";
    for(auto i:v){
        cout<<i<<" ";
    }
}

int main() {
//    BST b;
//    b.insert(4);
//    b.insert(2);
//    b.insert(1);
//    b.insert(3);
//    b.insert(6);
//    b.insert(5);
//    b.insert(7);
////    cout<<boolalpha<<b.search(4)<<"\n";
//    b.printBST();
////    b.deleteNode(1);
////    b.printBST();
////    cout<<boolalpha<<b.search(4)<<"\n";
//     b.bstToSLL();

vector<int> v1 = {1,2,3,4,5};
vector<int> v2{10,11,12,13,14,15};
v2 = move(v1);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    printVector(v1);
    printVector(v2);
    return 0;
}
