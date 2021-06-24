/*
NOTES:
1. Multimap is an associative container that contains a sorted list of key-value pairs,
while permitting multiple entries with the same key.
2. It store key value pair in sorted order on the basis of key (assending/decending).
3. Data structure used in multimap is not defined by standard, but red-black tree is assumed by most of the people.
4. Lookup: count, find, contains, equal_range, lower_bound, upper_bound
5. We dont have at() and [] functions to get element like we had in std::map.*/


#include<iostream>
#include<map>
using namespace std;

int main(int argc,char** argv){

  multimap<char,int> studentMarks;
  studentMarks.insert(make_pair('Y',0));
    studentMarks.insert(make_pair('A',0));
    studentMarks.insert(make_pair('Y',0));
    studentMarks.insert(make_pair('Y',0));

    for(auto &elm:studentMarks){
        cout<<elm.first<<" "<<elm.second<<endl;
    }


}
