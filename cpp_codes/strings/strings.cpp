#include<bits/stdc++.h>
using namespace std;
int main(){
    string s="Anshika";
    string t="#";
    for(int i=0;i<s.length();i++){
        t+=s[i];
        t+='#';
    }
    cout<<t<<" ";
}