#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
  int i,len,j,k,c=0,ans,s,temp,f=0;
	string n;
  cin>>n;
  len=n.size();
  int a[len];
  for(i=0;i<len;i++)
   {
     a[i]=n[i]-'0';
     if(a[i]==8 || a[i]==0)
      {
        c=1;
        ans=a[i];
      }
   }
  if(c==1)
  {
    cout<<"YES"<<endl;
    cout<<ans<<endl;
  }
  else
    {
      for(i=0;i<len;i++)
       {
         for(j=i+1;j<len;j++)
          {
            s=a[i]*10+a[j];
            if(s%8==0)
                {
                  c=1;
                  cout<<"YES"<<endl;
                  cout<<s<<endl;
                  break;
                }  
            for(k=j+1;k<len;k++)
             {
               int temp=s*10+a[k];
               if(temp%8==0)
                {
                  c=1;
                  cout<<"YES"<<endl;
                  cout<<temp<<endl;
                  break;
                }
             }
            if(c==1)
             break; 
          }
            if(c==1)
             break; 
        } 
       if(c!=1)
       cout<<"NO"<<endl; 
    }  
}