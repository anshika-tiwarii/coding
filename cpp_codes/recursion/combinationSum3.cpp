#include<bits/stdc++.h>

using namespace std;
void solve(int i,int k,int n,vector<int> &ds,vector<vector<int>> &answer,int currSum){
    //Base condition: method-1
    if (currSum>n) return;
    if (k==0){
        if(currSum==n){
            answer.push_back(ds);
        }
        return;
    }
    if (i>9) return;
    //Base condition: method-2
    // if (k<0) return;
    // if(currSum==n){
    //     if (k==0){
    //         answer.push_back(ds);
    //     }
    //     return;
    // }
    currSum+=i;
    // k-=1;
    ds.push_back(i);
    solve(i+1,k-1,n,ds,answer,currSum);
    ds.pop_back();
    // k+=1;
    currSum-=i;

    // ignore
    solve(i+1,k,n,ds,answer,currSum);

}
vector<vector<int>> combinationSumIII(int k,int n){
    vector<int> ds;
    vector<vector<int>> answer;
    int i=1;
    int currSum=0;
    solve(i,k,n,ds,answer,currSum);
    return answer;
}
int main(){
    int k=2;
    int n=18;
    vector<vector<int>> answer=combinationSumIII(k,n);
    
    for(auto it:answer){
        for(auto ele:it){
            
            cout<<ele<<" ";
            
        }
    }
    
}