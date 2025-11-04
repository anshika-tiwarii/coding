#include<bits/stdc++.h>
using namespace std;
string removesubstr(string s,string substring){
    // size_t type represents the size and indices and can never be negative
    size_t pos=s.find(substring);
    if (pos==string::npos){
        return s;
    }
    string leftover=s.substr(0,pos)+s.substr(pos+substring.length()); 
    // removes substring by extracting out the parts before and after the substring,from the string
    return removesubstr(leftover,substring);

}
int main(){
    string s="abcxxxxyyyyabcdh";
    string substring="xy";
    cout<<removesubstr(s,substring);

}