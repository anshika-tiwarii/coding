#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int i,int j,vector<vector<char>> &grid,vector<vector<int>> &vis){  
        int n=grid.size();
        int m=grid[0].size();      
        queue<pair<int,int>> q;
        q.push({i,j});
        vis[i][j]=1;
        int delRow[] = {-1, -1, -1, 0, 1, 1, 1, 0};
        int delCol[] = {-1,  0,  1, 1, 1, 0, -1, -1};
        while(!q.empty()){
            int r=q.front().first;
            int c=q.front().second;
            q.pop();
            for(int i=0;i<8;i++){
                int nrow=r+delRow[i];
                int ncol=c+delCol[i];
                while(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]==1){
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int numOfIslands(vector<vector<char>> &grid){
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int> (m,0));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    
                    cnt++;
                    bfs(i,j,grid,vis);
                }
            }
        }
        return cnt;
    }
};
int main() {
    // Create grid
    vector<vector<char>> grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };

    // Create Solution object
    Solution obj;
    // Call function and print result
    cout << obj.numOfIslands(grid) << endl;
    return 0;
}