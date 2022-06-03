#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  long long int n,i,temp,num;
  string s="";
  cin>>n;
  cin>>num;
  long long int a[10]={0};
  temp=num;
  for(i=0;i<n;i++)
   {
     a[temp%10]++;
     temp/=10;
   }
  // for(i=2;i<=9;i++) 
  //  cout<<"*"<<a[i]<<endl;
  for(i=9;i>=2;i--)
    {
      if(i==9)
       {
         a[2]+=a[9];
         a[7]+=a[9];
         a[3]+=(2*a[9]);
         a[9]=0;
         //cout<<a[3]<<endl;
       }
      else if(i==8)
       {
         a[2]+=(3*a[8]);
         a[7]+=a[8];
         a[8]=0;
       }
      else if(i==6)
       {
         a[3]+=a[6];
         a[5]+=a[6];
         a[6]=0;
         //cout<<a[3]<<endl;
       }
      else if(i==4)
       {
         a[2]+=(2*a[4]);
         a[3]+=a[4];
         a[4]=0;
         //cout<<a[3]<<endl;
       }   
    }
  for(i=9;i>=2;i--) 
   {
     while(a[i]!=0)
     {
        s+=to_string(i);
        a[i]--;
     }
   }
  cout<<s<<endl;  
}