#include<bits/stdc++.h>
#include<iostream>
using namespace std;
//HASHING IS USED
void solve(int col,int n,vector<string> &board,vector<vector<string>> &answer,vector<int> &leftRow,vector<int> &upperDiagonal,vector<int> &lowerDiagonal){
    if (col==n){
        answer.push_back(board);
        return;
    }
    for (int row=0;row<n;row++){
        if (leftRow[row]==0 && upperDiagonal[n-1+col-row]==0 && lowerDiagonal[row+col]==0){
            board[row][col]='Q';
            leftRow[row]=1;
            upperDiagonal[n-1+col-row]=1;
            lowerDiagonal[row+col]=1;
            solve(col+1,n,board,answer,leftRow,upperDiagonal,lowerDiagonal);
            board[row][col]='.';
            leftRow[row]=0;
            upperDiagonal[n-1+col-row]=0;
            lowerDiagonal[row+col]=0;
        }
    }
}
vector<vector<string>> nQueens(int n){
    vector<int> leftRow(n,0);
    vector<int> upperDiagonal(2*n-1,0);
    vector<int> lowerDiagonal(2*n-1,0);
    vector<string> board(n);
    vector<vector<string>> answer;
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solve(0,n,board,answer,leftRow,upperDiagonal,lowerDiagonal);
    return answer;


}
int main(){
    int n=4;
    vector<vector<string>> ans=nQueens(n);
    for(int i=0;i<ans.size();i++){
        cout<<"Arrangement"<<i+1<<" "<<endl;
        for(int j=0;j<ans[0].size();j++){
            cout<<ans[i][j];
            cout<<endl;
        }
        cout<<endl;
    }
}