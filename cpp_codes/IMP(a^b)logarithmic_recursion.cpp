#include<iostream>
#include<bits/stdc++.h>
using namespace std;
long long power(long long a,long long b){
    //base case: any number raised to 0 is 1
    if(b==0) 
    return 1;

    //recursive case: divide the power in half(logarithmic approach)
    long long half=power(a,b/2);
    // If b is even, a^b = (a^(b/2)) * (a^(b/2))
    // If b is odd, a^b = a * (a^(b/2)) * (a^(b/2))
    if(b%2==0){
        return half * half;
    }
    else{
        return a * half * half;
    }
}
int main(){
    int a,b;
    cout<<"enter base and exponent:";
    cin>>a>>b;
    cout<<power(a,b);
}
