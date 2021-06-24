#include<iostream>
#include <algorithm>

using namespace std;

class Edge{
public:
    int src;
    int dest;
    int weight;

    void printEdge(){
        cout<<"src : "<<src<<" "<<"dest  : "<<dest<<" "<<"weight : "<<weight<<endl;
    }
};

int find(int *parent,int vertice){
    while(vertice != parent[vertice]){
        vertice = parent[vertice];
    }
    return vertice;
}



Edge* kruskal(Edge *edges,int v,int e){
    int *set = new int[v];
    Edge *mst = new Edge[v-1];
    for(int i = 0;i<v;i++){
        set[i] = i;
    }

    auto  sortByWeight = [](const auto& a,const auto &b){return a.weight < b.weight;};

    sort(edges,edges+e,sortByWeight);

    for(int i = 0,j=0;i<e;i++){
        int x = find(set,edges[i].src);
        int y = find(set,edges[i].dest);
        if(x!=y){
            mst[j] = edges[i];
            j++;
            if(x<y){
                set[y] = x;
            }else{
                set[x] = y;
            }
        }
    }
   return mst;
}

int main(){
    int v,e;
    cin>>v>>e;
    Edge *edges = new Edge[e];
    for(int i = 0;i<e;i++){
        cin>>edges[i].src;
        cin>>edges[i].dest;
        cin>>edges[i].weight;
    }
    Edge *mst = kruskal(edges,v,e);
    for(int i = 0;i<v-1;i++){
        mst[i].printEdge();
    }
    delete []edges;
}

//5
//8
//0 1 9
//0 2 5
//1 2 10
//1 3 12
//2 3 7
//4 3 3
//4 2 6
//0 4 11