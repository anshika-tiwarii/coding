#include<bits/stdc++.h>
using namespace std;
//BFS
bool isCycle(int src,vector<int> adj[],int vis[]){
    vis[src]=1;
    queue<pair<int,int>> q;
    q.push({src,-1});
    while(!q.empty()){
        int node=q.front().first;
        int parent=q.front().second;
        q.pop();
        for(auto adjNode: adj[node]){
            if(!vis[adjNode]){
                vis[adjNode]=1;
                q.push({adjNode,node});
            }
            else if(adjNode!=parent){
                return true;
            }
        }
    }
    return false;
}
bool detectCycleBFS(int v,vector<int> adj[]){
    int vis[]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(isCycle(i,adj,vis)) return true;
        }
    }
    return false;
}
bool isCyc(int node,int parent,vector<int> adj[],int vis[]){
    vis[node]=1;
    for(auto adjNode:adj[node]){
        if(!vis[adjNode]){
            if(isCyc(adjNode,node,adj,vis)){
                return true;
            }            
        }
        else if(adjNode!=parent) return true;
    }
    return false;
}
bool detectCycleDFS(int v,vector<int> adj[]){
    int vis[v]={0};
    for(int i=0;i<v;i++){
        if(!vis[i]){
            if(isCyc(i,-1,adj,vis)) return true;
        }
    }
    return false;
}
int main() {    
    // V = 4, E = 2
    vector<int> adj[7] = {{2,3}, {1,5}, {1,4,6}, {3},{2,7},{3,7},{5,6}};
    
    bool ans1 = detectCycleBFS(7, adj);
    if (ans1)
        cout << "1\n";
    else
        cout << "0\n";

    bool ans2 = detectCycleDFS(7, adj);
    if (ans2)
        cout << "1\n";
    else
        cout << "0\n";    
    return 0;
}