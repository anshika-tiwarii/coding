#include<bits/stdc++.h>
using namespace std;
//this is method-1 of removing character 'a' from the string (passing both processed and unprocessed strings as arguments)

void removechar1(string unproc,string proc,char el){
    if(unproc.empty()) {
        cout<<proc;
        return;
    }
    char ch=unproc[0];
    if(ch=='a') removechar1(unproc.substr(1),proc,el);
    else removechar1(unproc.substr(1),proc+ch,el);
}


//this is method-2 of removing character 'a' from the string (passing only unprocessed string as argument)

string removechar2(string unproc,char el){
    if(unproc.empty()) {
        return "";
        
    }
    char ch=unproc[0];
    if(ch=='a') return ""+ removechar2(unproc.substr(1),el);
    else return ch + removechar2(unproc.substr(1),el);
}
int main(){
    string s="abracadabra";
    char el='a';
    removechar1(s,"",el);
    cout<<"\n";
    cout<<removechar2(s,el);

}