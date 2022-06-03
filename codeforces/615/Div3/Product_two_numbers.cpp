#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int t,n,i;
  cin>>t;
  while(t--)
   {
     int c=0,p=0,temp;
     cin>>n;
     temp=n;
     int a[3];
     for(i=2;i*i<=temp;i++)
      {
       if(c<2)
        {
          if(n%i==0)
           {
            c++;
            n/=i;
            a[p++]=i;
           }
        }
       else
        {
           break;  
        }
      }
     if(c<2)
       cout<<"NO"<<endl;
     else
       {
         if(a[1]==n || a[0]==n)
          cout<<"NO"<<endl;
         else
           {
            cout<<"YES"<<endl;
            cout<<a[0]<<" "<<a[1]<<" "<<n<<endl;
           } 
       }   
   }
}