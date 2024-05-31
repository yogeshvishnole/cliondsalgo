#include<iostream>
using namespace std;

/*
 * Priority Queue
 *
 * 1. Container adaptor that provides constant time lookup
 * of the largest (by default ) element , at the expense of logarithmic insertion and extraction
 * 2. Need to include <queue> header file
 * 3. A user provided compare can be supplied to change the ordering
 *   template<
 *   class T,
 *   class Container = std::vector<T>
 *   class Comapre = std::less<typename Container::valueType>
 *   >
 *   class priority_queue
 *
 *   Container
 *   1. The type of underlying container used to store elemnts of the priority
 *     queue
 *   2. Must satisfy the requirements of the sequence container,and its iterators
 *      must satisfy the requirements of LegacyRandomAccessIterator
 *   3. Additionally it must provide the following functions with usual semantics
 *      front() , push_back() ,pop_back()
 *   4. std::vector and std::deque satisfy these requirements
 *
 *  Compare
 *
 *  1. A compare type provideing a strict weak ordering
 *  2. Compare argument is defined such that , it returns
 *  true if its first argument comes before its second
 *  argument in a weak ordering.
 *
 *   Priority queue functions
 *  1. size
 *  2. =
 *  3. push(),pop()
 *  4. empty()
 *  5. top()
 *
 *
 * */



#include <queue>
#include <vector>

class Student{
    int age;
    int id;
    // -- TODO
};

int main() {
    /*
    priority_queue<int> Q;
    vector<int> v = {8, 1, 6, 4, 0, 7, 2, 9};
    for(int x : v) Q.push(x);
    while(!Q.empty()){
        cout << Q.top() << " ";
        Q.pop();
    }
    cout << endl;
    */

    /*
    priority_queue<int, vector<int>, std::greater<int>> Q;
    vector<int> v = {8, 1, 6, 4, 0, 7, 2, 9};
    for(int x : v) Q.push(x);
    while(!Q.empty()){
        cout << Q.top() << " ";
        Q.pop();
    }
    cout << endl;
    */

    auto cmp = [](int a, int b){
        return a > b;
    };

    priority_queue<int, vector<int>, decltype(cmp)> Q(cmp);
    vector<int> v = {8, 1, 6, 4, 0, 7, 2, 9};
    for(int x : v) Q.push(x);
    while(!Q.empty()){
        cout << Q.top() << " ";
        Q.pop();
    }
    cout << endl;

    return 0;
}

