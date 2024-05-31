#include <iostream>
#include<stack>
#include "2queueUsingLL.h"
using namespace std;

template<typename T>
void reverseQueue(Queue<T> &q){
    stack<int> s;
    while(!q.empty()){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
}

int main() {
    Queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reverseQueue(q);
    while(!q.empty()){
        cout<<q.front()<<"\n";
        q.pop();
    }
    q.pop();
    cout<<q.getSize()<<"\n";
    return 0;
}
