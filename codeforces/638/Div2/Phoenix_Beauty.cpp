#include <bits/stdc++.h>
using namespace std;

void beauty()
{
    int n,k,num;
    cin>>n>>k;
    set<int> s;
    for(int i=0;i<n;i++)
     {
         cin>>num;
         s.insert(num);
     }
    if(s.size()>k)
     {
        cout<<"-1"<<endl;
        return;
     }
    else
     {
        cout<<n*k<<endl;
        for(int i=0;i<n;i++)
         {
            for(auto it=s.begin();it!=s.end();it++)
             {
                cout<<*it<<" "; 
             }
            for(int j=0;j<k-s.size();j++)
             cout<<"1"<<" ";
         }
     }
}

int main(){
  int t; cin>>t;
  while (t--)
   {
       beauty();
       cout<<endl;
   }
}