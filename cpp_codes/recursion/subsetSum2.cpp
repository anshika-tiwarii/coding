#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void subsetSum2helper(int ind,vector<int> &arr,int n,vector<vector<int>> &ans,vector<int> &ds){
    ans.push_back(ds);
    for(int s=ind;s<n;s++){
        if(s!=ind && arr[s]==arr[s-1]) continue;
        ds.push_back(arr[s]);
        subsetSum2helper(s+1,arr,n,ans,ds);
        ds.pop_back();
        }
    }

vector<vector<int>> subsetSum2(vector<int>&arr,int n){
    vector<vector<int>> ans;
    vector<int> ds;
    sort(arr.begin(),arr.end());
    subsetSum2helper(0,arr,n,ans,ds);
    return ans;
}
int main(){
    vector<int> arr={1,2,2};
    int n=arr.size();
    vector<vector<int>>ans=subsetSum2(arr,n);
    cout<<"[";
    for(int i=0;i<ans.size();i++){
        cout<<"["<<" ";
        for(int j=0; j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"]";
    }
    cout<<"]";
}