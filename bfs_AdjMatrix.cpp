// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
void print_graph(vector<vector<int>>&adjMat){
    for(auto i=0; i<adjMat.size(); i++){
        cout<<"Node "<<i<<" is connected to: ";
        for(int j=0; j<adjMat.size();j++){
            if(adjMat[i][j]==1){
                cout<<j<<" ";
            }
        }cout<<endl;
    }
}
void bfs(vector<vector<int>>&adjMat, int start){
    queue<int>q;
    vector<bool>visited(adjMat.size(),0);
    q.push(start);
    visited[start]=1;
    
    while(q.size() != 0){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        
        for(int i=0; i<adjMat.size(); i++){
            if(adjMat[node][i]==1 and !visited[i]){
                q.push(i);
                visited[i]=1;
            }
        }
    }
}
int main() {
    // Write C++ code here
    vector<pair<int,int>>edgeList{{0,1},{1,2},{2,3},{3,0},{3,1}};
    vector<vector<int>>adjMat(4,vector<int>(4,0));
    for(auto it : edgeList){
        int a = it.first, b = it.second;
        adjMat[a][b]=1;
        adjMat[b][a]=1;
    }
    print_graph(adjMat);
    bfs(adjMat, 0);
    
    return 0;
}
