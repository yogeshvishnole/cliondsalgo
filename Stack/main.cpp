#include <iostream>
#include "4StackUsingLinkedList.h"
#include "3StackClassUsingVector.h"
using namespace std;

int main() {
    llstack::Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    cout<<s.size()<<"\n";
    int currStackSize = s.size();
    for(int i = 0;i<currStackSize;i++){
        cout<<s.top()<<"\n";
        s.pop();
    }
    s.pop();
    cout<<boolalpha<<s.isEmpty()<<"\n";
    cout<<s.size()<<"\n";

    return 0;
}
