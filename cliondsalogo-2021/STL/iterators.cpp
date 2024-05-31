#include<iostream>
#include<unordered_map>
using namespace std;

/*
 *  Iterators
 *
 *  Objects that enable traversal of containers in some order , for either reading or writing
 *
 *  Iterators are defined as templates and must comply with a very specific set of rules in
 *  order to qualify as one of many types of iterators.
 *
 *  Are pointers and iterators are same thing ?
 *
 *  No
 *
 *  Pointers are variables that can be indirected to refer to a memory location.
 *
 *  Iterator is a higher abstraction for elements used to traverse containers ,
 *  whereas pointers and integers are special type of iterators , not suitable for
 *  every container
 *
 * Types of iterators
 *
 * 1. Input iterator
 * 2. Output Iterator
 * 3. Forward iterator
 * 4. Bidirectional iterator
 * 5. RandomAccess iterator
 *
 * All containers require their iterators to comply with the capabilities
 * of some of these types . Some are rather relaxed and some are more rigorous.
 *
 * Input iterator
 *
 * Only able to read (only accessing , not assigning)
 * Only moves forwrd
 * Can be incremented ( ++it,it++ notpossible --> --it,it--)
 * Only one pass possible
 * Least requirement supported by stl
 * suitable for input streams like keyboard buffer and read-only files
 *
 * Output iterators
 *
 * Only able to write
 * Only moves forward
 * Only one pass possible
 * Least requirement supported by stl
 * suitable for output streams such as screen text and write-only files
 *
 * Forward iterator
 *
 * It has the requirements of both the input and output iterators.
 * Able to read and write and
 * only moves forward
 * support multiple passes of container
 * suitable for traversing singly linked list
 *
 * Bidirectional iterators
 *
 * ALl capabilities of forward iterators + backward traversal
 * Suitable for doubly linked list
 *
 * Random-Access iterators
 *
 * ALl capabilities of  Bidirectional iterators + Random access by means of indexing
 * Suitable for vectors and similar containers(array).
 *
 * Iterator functions
 *
 * 1. begin()
 *
 * Returns iterator to the beginning of the container
 *
 * 2. end()
 *
 * Returns an iterator to the element following the last element of the container
 * This element act as a placeholder , attempting to acces it results in undefined behaviour
 *
 * 3. rbegin()
 *
 *   Returns iterator to the last element of the container
 *
 * 4. rend()
 *
 *    Returns a reverse iterator pointing to the theoretical element right before the first element in the
 *    array container.
 *
 *    Iterator Invalidation
 *
 *    1. Due to update (insert/delete) of conatiner that is using iterators'
 *    2. No runtime error but iterator no longer guaranteed to have access to
 *       the same element after update.
 *    3. Well documented rules
 *    4. Depends on container implementation
 *
 * */

int main(int argc,char **argv){
// iterator example
unordered_map<string,int> um;
um["abc"] = 0;
um["abc1"] = 1;
um["abc2"] = 2;
um["abc3"] = 3;
um["abc4"] = 4;

for(unordered_map<string,int>::iterator it = um.begin();it!=um.end();it++){
    cout<<it->first<<" "<<it->second<<endl;
}
}