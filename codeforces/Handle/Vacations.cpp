#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n,i,num,j,k;
    cin>>n;
    char a[101];
    for(i=0;i<n;i++)
     {
       cin>>num;
       if(num==0)
        a[i]='N';
       else if(num==1)
        a[i]='C';
       else if(num==2)
        a[i]='G';
       else 
        a[i]='B';   
      }
  //  for(i=0;i<n;i++)
  //   cout<<a[i]<<" ";
  //  cout<<endl;    
   for(i=0;i<n-1;i++)
    {
     if(a[i]!='N')
     {
      if(a[i]==a[i+1] && a[i]!='B')
       a[i+1]='N';
      else if(a[i]=='G' && a[i+1]=='B')
       a[i+1]='C';
      else if(a[i]=='C' && a[i+1]=='B')
       a[i+1]='G';
      else if(a[i]=='B' && a[i+1]=='C')
       a[i]='G';
      else if(a[i]=='B' && a[i+1]=='G')
       a[i]='C';  
      else if(a[i]=='B' && a[i+1]=='B')
       {
         for(j=i+2;j<n;j++)
        if(a[j]!='B')
        break;
         for(k=j-1;k>=i;k--)
          {
            if(a[k+1]=='G' || a[k+1]=='N')
             a[k]='C';
            else if(a[k+1]=='C')
             a[k]='G';
          } 
         i=j-1; 
       }
     }    
    }
  int count=0;  
  for(i=0;i<n;i++)
   {
    if(a[i]=='N') 
     count++;
   }
  cout<<count<<endl;     
}
