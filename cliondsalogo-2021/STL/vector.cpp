#include<iostream>
#include<vector>
using namespace std;


/*
 *
 *  Vectors
 *
 *  1. Elements are stored contiguosly.
 *  2. Storage of vector is handled automatically , being expanded and contracted as needed
 *  3. Vectors usually occupy more space than static arrays, because more memory is allocated
 *     to handle future growth
 *
 *  Vector functions
 *
 *  1. size() , capacity() , max_size()
 *  2. = for initialization by initializer list , [] --> no bound check , at --> bound check
 *  3. front() , back()
 *  4. shrink_to-fit()
 *  5. empty()
 *  6. begin() , end() ,rbegin() ,rend()
 *  7. insert (it , element to insert) or insert(it,it1,it2) , erase(it1,it2) it1 included it2 not
 *  8. push_back() , pop_back()
 *  9. clear() --> clear the list
 * */

int main(int argc,char **argv){
    vector<int> v = {1,2,3};
    cout<< v.size() << " \n";
}
