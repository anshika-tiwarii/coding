#include<iostream>
#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
    // input string
    // string str;
    // cout<< "enter the string";
    // getline(cin,str);
    // cout<<"the string is:" <<"  " << str;
    // return 0; 

    
    // string s= "anshika";
    // cout<< s[2] <<"   ";
    // int len= s.size();
    // s[len-1] ='s';
    // cout<< s;


    // char ch;
    // cout<< "enter some character:";
    // cin>> ch;
    // cout<< "the ASCII value for the entered thing is:" << int(ch);

    // int n;
    // cout<<"enter a number";
    // cin>> n;
    // cout<<"the character value for it is:"<< char(n);


    // print the table of a number
    // int i,n;
    // cout<<"please enter a number"<<endl;
    // cin>>n;
    // for(i=n;i<=10*n;i+=n){
    //   cout<<i<<" ";
    // }

    // prime or composite
    // int i,n;
    // cout<<"enter a number" << endl;
    // cin>>n;
    // bool flag=true;
    // for(i=2;i<=n/2;i++){
    //   if(n%i==0){
    //       flag= false;
    //       break;    } 
    // }
    // if(n==1) cout<<"neither prime nor composite";
    // else if(flag==false) cout<<"composite";
    // else cout<<"prime";

  //  print the sum of even digits of a number
  //  int i,n,sum=0,ld;
  //  cout<<"enter a number";
  //  cin>>n;
  //  while(n!=0){
  //   ld=n%10;
  //   n/=10;
  //   if (ld%2==0){
  //     sum+=ld;
  //   }
  //  cout<<sum;


  // sum from 1 to n
  // int i,n,sum=0;
  // cout<<"enter a number";
  // cin>>n;
  // for(i=1;i<=n;i++){
  //   sum+=i;
  // }
  // cout<<sum;


  // int n,rev=0,ld;
  // cout<<"enter a number";
  // cin>>n;

  // while(n!=0){
  //   ld=n%10;
  //   rev*=10;
  //   rev+=ld;
  //   n/=10;
  // }
  // cout<<rev;

  // print the factorial of a given number
  // int i,n,fact=1;
  // cout<<"enter a number"<<" ";
  // cin>>n;
  // for(i=1;i<=n;i++){
  //   fact*=i;
  //   cout<<fact<<"  "; 
  // }

 
  // for(int i=65;i<=90;i++){
  //   cout<<char(i)<<" "<<i<<endl;
  // }

// int i,j;
//   for (i=1;i<=4;i++){
//     for (j=1;j<=4;j++){
//       cout<<(char)(j+96)<<" "<<j+96<<" ";
//     }
//     cout<<endl;
//   }

// int i,j;
//   for (i=1;i<=5;i++){
//     for (j=1;j<=i;j++){
//       cout<<j<<" ";
//     }
//     cout<<endl;
//   }


// int i,j,n;                                  */*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/
// cout<<"enter a no";
// cin>>n;
// for(i=1;i<=n;i++){
//   for(j=1;j<=i;j++){
//     if(i%2!=0){
//     cout<<j<<" ";
//     }
//     else{
//       cout<<char(j+64)<<" ";
//     }
//   }
//   cout<<endl;
// }

// int i,j;
// for(int i=1;i<=5;i++){
//   for(j=1;j<=5-i+1;j++){
//     cout<<j;
//   }
//   cout<<endl;
// }

// int i,j;                                   */*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/
// for(i=0;i<4;i++){
//   for(j=4;j>4-i-1;j--){
//     cout<<j;
//   }
//   cout<<endl;
// }

// int i,j,n,a=1;
// cout<<"enter some no";
// cin>>n;
// for(i=1;i<=n;i++){
//   for(j=1;j<=i;j++){
//     cout<<a<<" ";
//     a++;
//   }
//   cout<<endl;
// }

// int i,j,n;
// cout<<"enter a number";
// cin>>n;
// for(i=1;i<=n;i++){
//   for(j=1;j<=i;j++){
//     if((i+j)%2==0){
//       cout<<1<<" ";
//     }
//     else{
//       cout<<0<<" ";
//     }
//   }
//   cout<<endl;
// }

// int i,j,n;
// cout<<"enter a number";
// cin>>n;
// int mid=n/2+1;
// for(i=1;i<=n;i++){
//   for(j=1;j<=n;j++){
//     if(i==mid or j==mid){
//       cout<<"* ";
//     }
//     else{
//       cout<<"  ";
//     }
//   }
//   cout<<endl;
// }

// int i,j,m,n;
// cout<<"enter L and B of rect";
// cin>>m>>n;
// for(i=1;i<=n;i++){
//   for(j=1;j<=m;j++){
//     if(i==1 or i==n or j==1 or j==m){
//       cout<<"* ";
//     }
//     else{
//       cout<<"  ";
//     }
//   }
//   cout<<endl;
// }

// int i,j,n;
// cout<<"enter a number"<<endl;
// cin>>n;
// for(i=1;i<=n;i++){
//   for(j=1;j<=n;j++){
//     if(i==j or j==n-i+1){
//       cout<<"* ";
//     }
//     else{
//       cout<<"  ";
//     }
//   }
//   cout<<endl;
// }

// int i,j,n;
// cout<<"enter a number"<<endl;
// cin>>n;
// for(i=1;i<=n;i++){
//   for(j=1;j<=n-i;j++){
//     cout<<" ";
//   }
//   for(j=1;j<=i;j++){
//     cout<<"*";
//   }
//   cout<<endl;
//   }

// int i,j,n;
// cout <<"enter a number"<<" ";
// cin>>n;
// for(i=1;i<=n;i++){
//   for(j=1;j<=i-1;j++){
//     cout<<" ";
//   }
//   for(j=n-i+1;j>=1;j--){
//     cout<<"*";
//     }  
//   cout<<endl;
// }

// int i,j,n;
// cout <<"enter a number"<<" ";
// cin>>n;
// for(i=0;i<n;i++){
//   for(j=0;j<n-i-1;j++){
//     cout<<" ";
//   }
//   for(j=1;j<=2*i+1;j++){
//     cout<<j;
//   }
//   cout<<endl;
// }

// int i,j,n;                                  ///*/*/*/*/*/*/*/*/*/*/*/
// cout <<"enter a number"<<" ";
// cin>>n;
// int nspaces=n-1;
// for(i=1;i<=n;i++){
// //   for(j=1;j<=nspaces;j++){
// //     cout<<" ";
// //   }
// //   nspaces--;
// // for(j=1;j<=i;j++){
// //   cout<<j;
// // }
// int a=i-1;
// for(j=1;j<=i-1;j++){
//   cout<<a;
//   a--;
// }
// cout<<endl;
// }

// int i,j,n;
// cout <<"enter a number"<<" ";
// cin>>n;
// int nst=n;
// int nsp=1;
// for(i=1;i<=2*n+1;i++){
//   cout<<"*";
// }
// cout<<endl;
// for(i=1;i<=n;i++){
//   for(j=1;j<=nst;j++){
//     cout<<"*";
//   }
//   for(j=1;j<=nsp;j++){
//     cout<<" ";
//   }
//   for(j=1;j<=nst;j++){
//     cout<<"*";
//   }
//   nst--;
//   nsp+=2;
//   cout<<endl;

// int i,j,n,cubesum=0,dup,ld;                                
// cout <<"enter a number"<<" ";
// cin>>n;
// dup=n;
// while(n!=0){
// ld=n%10;
// cubesum+=(ld*ld*ld);
// n/=10;
// }
// cout<<cubesum<<'\n';
// if(cubesum==dup){
//   cout<<"armstrong number check";
// }
// else{
//   cout<<"not armstrong";
// }

int n;
cout<<"enter a number";
cin>>n;
for(int i=0;i<n;i++){
  for(int j=0;j<i;j++){
    cout<<" ";
  }
  for(int j=0;j<n-i;j++){
    cout<<i+1<<" ";
  }
  
  cout<<endl;
}















  




















    
        


  








  

 









    
}