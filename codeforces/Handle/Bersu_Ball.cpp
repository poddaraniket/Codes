#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n,m,i,j,num,c=0,tem,diff,result=0;
    vector<int> b,g;
    cin>>n;
    for(i=0;i<n;i++)
     {
         cin>>num;
         b.push_back(num);
     }
    cin>>m;
    for(i=0;i<m;i++)
     {
         cin>>num;
         g.push_back(num);
     }
    tem=max(n,m); 
    sort(b.begin(),b.end());
    sort(g.begin(),g.end());
    i=0;
    j=0;
    for(;i<m;)
     {
         for(;j<n;)
          {
              c=1;
              diff=abs(g[i]-b[j]);
              if(diff<=1)
               {
                   result++;
                   //cout<<dp[p]<<" "<<p<<endl;
                   j++;
                   i++;
               }
              else
                {
                    //cout<<dp[p]<<endl;
                    if(g[i]>b[j])
                     j++;
                    else
                     i++;
                }
          }
        if(c==1)
          c=0;
        else
          {
              break;
          }
        //p++;  
     }
    cout<<result<<endl; 
}
