#include<iostream>
#include<vector>
#include<stack>
using namespace std;

// Time and space complexity of dfs
// time == O(V+E)
// space == O(V+E)

void dfs(vector<vector<int>> &graph,int i,vector<bool> &visited){
    visited[i] = true;
    cout<<i<<" ";
    for(int child:graph[i]){
        if(visited[child] == false){
            dfs(graph,child,visited);
        }
    }

}

void dfsStack(vector<vector<int>> &graph,int i,vector<bool> &visited){
    stack<int> s;
    s.push(i);
    visited[i] = true;
    while(!s.empty()){
        int curEl = s.top();
        cout<<curEl<<" ";
        s.pop();
        for(int child:graph[curEl]){
            if(!visited[child]){
                s.push(child);
                visited[child] = true;
            }
        }
    }
}


int main(){
    int v;
    int e;
    cin>>v>>e;
    vector<vector<int>> graph(v+1);
    vector<bool> visited(v+1,false);
    while(e--){
        int a;
        int b;
        cin>>a;
        cin>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    cout<<"Enter the start of dfs : ";
    int i;
    cin>>i;
//    dfs(graph,i,visited);
dfsStack(graph,i,visited);
}