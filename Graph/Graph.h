//
// Created by dell on 12/06/21.
//

#ifndef GRAPH_GRAPH_H
#define GRAPH_GRAPH_H
#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Graph{

public:
    int v,e;
    int **adjacencyMatrix;

    Graph(int v,int e):v{v},e{e}{
        adjacencyMatrix = new int*[v];
        for(int i = 0;i<v;i++){
            adjacencyMatrix[i] = new int[v];
            for(int j = 0;j<v;j++){
                adjacencyMatrix[i][j] = 0;
            }
        }
        for(int i = 0;i<e;i++){
            int src;
            int dest;
            int weight;
            cin>>src>>dest>>weight;
            adjacencyMatrix[src][dest] = weight;
            adjacencyMatrix[dest][src] = weight;
        }
    }

    void dfs(int sI,bool *visited){
        cout<<sI<<" ";
        visited[sI] = true;
        for(int i = 0;i<v;i++){
            if(!visited[i] && adjacencyMatrix[sI][i] == 1){
                dfs(i,visited);
            }
        }
    }

    void dfsUsingStack(int sI,bool *visited){
        stack<int> s;
        s.push(sI);
        while(!s.empty()){

            int curEl  = s.top();
            if(visited[curEl] ==false){
                cout<<curEl<<" ";
            }
            visited[curEl] = true;

            s.pop();
            for(int i = 0;i<v;i++){
                if(!visited[i] && adjacencyMatrix[i][curEl] == 1 ){
                    s.push(i);
                }
            }

        }
    }

    void bfs(int sI,bool *visited){
         queue<int> q;
         q.push(sI);
        visited[sI] = true;
         while(!q.empty()){
             int curEl = q.front();
             q.pop();
             cout<<curEl<<" ";
             for(int i = 0;i<v;i++){
                 if(!visited[i] && adjacencyMatrix[i][curEl] == 1){
                     q.push(i);
                     visited[i] = true;
                 }
             }
         }
    }

    void bfsForDisconnected(int sI,bool *visited){
        bfs(sI,visited);
        int count = 1;
        for(int i = 0;i<v;i++){
            if(!visited[i]){
                bfs(i,visited);
                count++;
            }
        }
        cout<<"No. of disconnected components : "<<count<<endl;
    }

    void dfsForDisconnected(int sI,bool *visited){
        dfs(sI,visited);
        int count = 1;
        for(int i = 0;i<v;i++){
            if(!visited[i]){
                dfs(i,visited);
                count++;
            }
        }
        cout<<"No. of disconnected components : "<<count<<endl;
    }

void prims(){
        bool *visited = new bool[v];
        int *parent = new int[v];
        int *weights = new int[v];
        for(int i=0;i<v;i++){
            visited[i] = false;
            weights[i] = INT32_MAX;
            parent[i] = -1;
        }
        parent[0] = 0;
        weights[0] = 0;
        for(int i=0;i<v;i++){
            int curEl = INT32_MAX;
            int curIndex;
            for(int i=0;i<v;i++){
               if(curEl > weights[i] && !visited[i]){
                   curEl = weights[i];
                   curIndex = i;
               }
            }
            visited[curIndex] = true;
            for(int i = 0;i<v;i++){
                if(!visited[i] && adjacencyMatrix[i][curIndex]){
                    if(adjacencyMatrix[i][curIndex] < weights[i]){
                        weights[i] = adjacencyMatrix[i][curIndex];
                        parent[i] = curIndex;
                    }

                }
            }
        }

        for(int i = 1;i<v;i++){
            cout<<parent[i]<<" "<<i<<" "<<weights[i]<<endl;
        }
        delete []visited;
        delete []parent;
        delete []weights;
    }

};

#endif //GRAPH_GRAPH_H
