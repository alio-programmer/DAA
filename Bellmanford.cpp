#include<iostream>
#include<vector>
using namespace std;

vector<int> bellmanford(int v, vector<vector<int>> &edges, int s){
    vector<int> dist(v, 1e9);
    dist[s] = 0;
    for(int i=0; i<v-1; i++){
        for(auto it: edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if(dist[u]!=1e9 && dist[u]+wt<dist[v]){
                dist[v]=dist[u]+wt;
            }
            if(dist[u]!=1e9 && dist[u]+wt<0){
                return {-1};
            }
        }
    }
    return dist;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> adj;
    for(int i = 0; i<m; i++){
        int u,v,wt;
        cin>>u>>v>>wt;
        adj.push_back({u,v,wt});
    }
    vector<int> dist = bellmanford(4, adj, 3);
    for(auto it: dist){
        if(it==-1){
            cout<<"The graph has negative cycle in it"<<endl;
            break;
        }
        cout<<it<<" ";
    }
    return 0;
}
