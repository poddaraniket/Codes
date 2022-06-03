#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
  long long int n,c=0,i;
  cin>>n;
  long long int xi[n],ht[n],dist[n];
  for(i=0;i<n;i++)
   cin>>xi[i]>>ht[i];
  //long long int dist[n];
  for(i=0;i<n-1;i++)
   dist[i]=abs(xi[i]-xi[i+1]);
  // for(i=0;i<n-1;i++)
  //   cout<<dist[i]<<endl;
  for(i=1;i<n-1;i++)
   {
     if(ht[i]<dist[i-1])
      {
        c++;
        dist[i-1]-=ht[i];
      }
      else if(ht[i]<dist[i])
       {
         c++;
         dist[i]-=ht[i];
       }
   }
  if(n>2) 
   cout<<c+2<<endl;
  else
   cout<<n<<endl;    
}