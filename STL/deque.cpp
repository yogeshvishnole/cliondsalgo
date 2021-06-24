#include<iostream>
#include<deque>
using namespace std;

/*
 *  deque
 *
 *  Sequence container supports push / pop from both ends
 *  supports random access
 *  Need to include deque header file
 *  Elements are not stored contiguosly : typical implementations use a sequence of individually
 *  fixed-size arrays , with additional bookkeeping.
 *
 *   Deque functions
 *
 *  1. size()
 *  2. = for initialization by initializer list , []
 *  3. front() , back()
 *  4.. empty()
 *  5. begin() , end() ,rbegin() ,rend()
 *  6. insert (it , element to insert) or insert(it,it1,it2) , erase(it1,it2) it1 included it2 not
 *  7. push_back() , push_front() , pop_front() ,  pop_back()
 *  8. clear()
 *
 *
 * */

int main(){

    deque<int> d = {1,3,5,7};
    cout<< "Size = "<<d.size()<<"\n";

    for(deque<int>::iterator it = d.begin();it != d.end();it++){
        cout<<*it<<" ";
    }
    cout<<"\n";
    for(deque<int>::reverse_iterator  it = d.rbegin();it != d.rend();it++){
        cout<<*it<<" ";
    }


}
