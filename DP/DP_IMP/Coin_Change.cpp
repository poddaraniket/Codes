#include <bits/stdc++.h>

using namespace std;

int main() {
  int s,i,j;
  int a[]={9, 6, 5, 1};
  s=11;
  //cout<<s<<endl;
  //int a[n];
  int Min[s+1];
  Min[0]=0; 
  for(i=1;i<=s;i++)
   Min[i]=1000000;
  //i=1; 
  for(i=1;i<=s;i++)
   {
     for(j=0;j<4;j++)
      {
        //cout<<"*"<<a[j]<<endl;
        //cout<<a[j]<<endl;
        if(a[j]<=i && Min[i-a[j]]+1<Min[i])
         { 
           Min[i]=Min[i-a[j]]+1;
           //cout<<Min[i]<<endl;
         }
      }
   // i++;  
   }
  cout<<Min[s]<<endl;  
}