#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int> nums={-1,-5,-7,-3,-9};
    sort(nums.rbegin(),nums.rend());
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<" ";
    }
}