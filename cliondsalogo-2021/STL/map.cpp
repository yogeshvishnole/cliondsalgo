

//NOTES:
//1. std::map is associative container that store elements in key value combination
//        where key should be unique, otherwise it overrides the previous value.
//2. It is implement using Self-Balance Binary Search Tree (AVL/Red Black Tree) .
//3. It store key value pair in sorted order on the basis of key (assending/decending).
//4. std::map is generally used in Dictionay type problems.

//Syntax = map<T1,T2> obj;

#include<iostream>
#include<map>
using namespace std;

int main(int argc,char** argv){

    map<string,int> studentMarks;
    studentMarks["Ram"] = 5;
    studentMarks["Ram"] = 5;
    studentMarks["Ram"] = 5;
    studentMarks.insert(make_pair("Yogesh",10));
    studentMarks.insert(make_pair("Aram",20));

    for(auto &el:studentMarks){
        cout<<el.first<<" "<<el.second<<endl;
    }


}
