#include<bits/stdc++.h>
#include<iostream>
using namespace std;
bool isSafe(int row,int col,int n,vector<string> &board){
    int duprow=row;
    int dupcol=col;
    while(row>=0 && col>=0){
        if(board[row][col]=='Q') return false;
    row--;
    col--;
    }
    
    row=duprow;
    col=dupcol;
    while(col>=0){
        if(board[row][col]=='Q') return false;
    col--;
    }

    row=duprow;
    col=dupcol;
    while(row<n && col>=0){
        if(board[row][col]=='Q') return false;
    row++;
    col--;
    }
    return true;

}
void solve(int col,int n,vector<string> &board,vector<vector<string>> &answer){
    if (col==n){
        answer.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if (isSafe(row,col,n,board)){
            board[row][col]='Q';
            solve(col+1,n,board,answer);
            board[row][col]='.';
        }
    }
}
vector<vector<string>> nQueens(int n){
    vector<string> board(n);
    vector<vector<string>> answer;
    string s(n,'.');
    for(int i=0;i<n;i++){
        board[i]=s;
    }
    solve(0,n,board,answer);
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