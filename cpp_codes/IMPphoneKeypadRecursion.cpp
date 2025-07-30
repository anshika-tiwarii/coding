#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void findcombination(string digits,vector<string> &answer,string op,int index,string mapping[]){
    if (index>=digits.length()){
        answer.push_back(op);
        return;
    }
    int num=digits[index]-'0';
    string valueAtnum=mapping[num];
    for(int i=0;i<valueAtnum.length();i++){
        op.push_back(valueAtnum[i]);
        findcombination(digits,answer,op,index+1,mapping);
        op.pop_back();
    }

}
vector <string> letterCombination(string digits){
    int index=0;
    vector<string> answer;
    string op="";
    if (digits.length()==0){
        return answer;
    }
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    findcombination(digits,answer,op,index,mapping);


}
int main(){
    string digits="23";
    vector <string> answer=letterCombination(digits);
    cout<<"{";
    for (const auto &it: answer){
        cout<<it<<" ";
    }
    cout<<"}"; 
}
