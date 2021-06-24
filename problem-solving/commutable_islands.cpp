#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



bool compare(vector<int>& a,vector<int>& b){
    return a[2] < b[2];
}

int find(vector<int> &set,int i){
    while(i != set[i]){
        i = set[i];
    }
    return i;
}

int solve(int A, vector<vector<int> > &B) {

    vector<vector<int>> adjMat(A+1);

    for(int i =0;i<=A;i++){
        for(int j = 0;j<=A;j++){
            adjMat[i].push_back(INT32_MAX);
        }
    }

    for(int i = 0;i<B.size();i++){
        adjMat[ B[i][0]  ][ B[i][1]  ] = B[i][2];
        adjMat[ B[i][1] ][ B[i][0] ] = B[i][2];
    }

    vector<int> vertex(A+1);
    vector<int>  parent(A+1,-1);
    vector<int> weights(A+1,INT32_MAX);
    vector<bool> visited(A+1,false);

    for(int i =0;i<=A;i++){
        vertex[i] = i;
    }

    parent[1] = 0;
    weights[1] = 0;

    for(int i = 1;i<=A;i++){
        int min_index;
        int min_element = INT32_MAX;
        for(int i = 1;i<weights.size();i++){
            if(!visited[i] && weights[i] < min_element){
                min_element = weights[i];
                min_index = i;
            }
        }
        visited[min_index] = true;

        for(int i = 1;i<=A;i++){
            if(!visited[i] && adjMat[i][min_index]<weights[i]){
                weights[i] = adjMat[i][min_index];
                parent[i] = min_index;
            }
        }

    }

    int sum = 0;
    for(int i = 1;i<=A;i++){
        sum+=weights[i];
    }
    return sum;

}

int main(){
    int A =4;
    vector<vector<int>>B{
            {1, 2, 1},
            {2, 3, 2},
            {3, 4, 4},
            {1, 4, 3}
    };
    cout<<solve(A,B);

}