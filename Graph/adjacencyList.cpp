#include<iostream>
#include<vector>
#include<utility>
using namespace std;
typedef pair<int,int> pa;

int main(){
    int v;
    int e;
    cin>>v>>e;

    vector<vector<pa>> graph(v+1);

    while(e--){
        int a;
        int b;
        int weight;
        cin>>a>>b;
        graph[a].push_back(make_pair(b,weight));
        graph[b].push_back(make_pair(a,weight));
    }
}