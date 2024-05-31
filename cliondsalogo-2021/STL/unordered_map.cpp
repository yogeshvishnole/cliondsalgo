#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

vector<int> removeDuplicates(int arr[],int n){
    unordered_map<int,int> arrayNumberCounts;
    vector<int> result;
    for(int i = 0;i<n;i++){
        arrayNumberCounts[arr[i]]++;
    }
    for(int i = 0;i<n;i++){
        if(arrayNumberCounts.at(arr[i]) > 0){
            arrayNumberCounts[arr[i]] = 0;
            result.push_back(arr[i]);
        }
    }
    return result;
}

int main(int argc,const char* argv[]){
//    unordered_map<string,int> studentGrades;
//    studentGrades.insert(make_pair("Yogesh",90));
//    cout<<studentGrades.at("Yogesh")<<"\n";

//int arr[] = {1,2,3,2,1,5,4,1,3};
//vector<int> nodups = removeDuplicates(arr,9);
//for(auto i:nodups){
//    cout<<i<<" ";
}


}