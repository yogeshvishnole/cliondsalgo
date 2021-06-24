#include<iostream>
#include<list>
using namespace std;

/*
 *  Sequence containers ,optimized for rapid insert and delete operations
 *  Elements are stored non contiguosly
 *  Doesn't support random access
 *  Bidirectional iterators ( 1 direction for forward list)
 *
 *     List functions
 *
 *  1. size()  , max_size()
 *  2. = for initialization by initializer list
 *  3. front() , back()
 *  4.. empty()
 *  5. begin() , end() ,rbegin() ,rend()
 *  6. insert (it , element to insert) or insert(it,it1,it2) , erase(it1,it2) it1 included it2 not
 *  remove(element)
 *  7. push_back() , push_front() , pop_front() ,  pop_back()
 *  8. clear()
 *
 * */

void print_list(list<int> &ll) {

    for(list<int>::iterator it = ll.begin();it != ll.end();it++){
        cout<<*it<<" ";
    }

}


int main(){

    list<int>  ll  = {2,4,6,8};
    print_list(ll);

}