#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
     {
         int n,q;
         cin>>n>>q;
         vector<pair<long long int,long long int>> v;
         for(int i=0;i<n;i++)
          {
              long long int x,y;
              cin>>x>>y;
              v.push_back({x,y});
          }
          sort(v.begin(),v.end());
          vector<pair<long long int,long long int>> vec;
          int i=1,p=0;
          vec.push_back(v[0]);
          long long int val=vec[0].second;
          while(i<n){
              if(vec[p].second>=v[i].first)
               {
                   if(vec[p].second<v[i].second)
                    vec[p].second=v[i].second;
               }
               else {
                   vec.push_back(v[i]);
                   p++;
               }
            i++;
          }
         while(q--){
             long long int val,ans=-1;
             cin>>val;
             for(long long int i=0;i<vec.size();i++)
              {
                  long long int diff=vec[i].second-vec[i].first+1;
                  if(val<=diff)
                   {
                       ans=vec[i].first+val-1;
                       break;
                   }
                   else
                    val-=diff; 
              }
             cout<<ans<<endl;
         }
     }
}