#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int fibonacci(int n){                               //TO FIND FIBONACCI SERIES KA Nth TERM
    if(n==1|| n==2) return 1;
    return fibonacci(n-1) + fibonacci(n-2);      
}
int main(){
    int a;
    cout<<"enter the term";
    cin>>a;
    cout<<fibonacci(a);    
}






















