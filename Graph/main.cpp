#include <iostream>
#include<cstring>
#include"Graph.h"
using namespace std;

int main() {
    int v,e;
    cin>>v;
    cin>>e;
    Graph g(v,e);
   g.prims();
    return 0;
}
