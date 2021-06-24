#include<iostream>
#include<vector>
using namespace std;

int main(){
    int v;
    int e;
    cin>>v>>e;
    vector<vector<int>> graph(v+1);

    for(int i  =0;i<=v;i++){
        for(int j = 0;j<=v;j++){
            graph[i][j] = 0;
        }
    }

    while(e--){
        int a;
        int b;
        int weight;
        cin>>a>>b>>weight;
        graph[a][b] = weight;
        graph[b][a] = weight;
    }
}

