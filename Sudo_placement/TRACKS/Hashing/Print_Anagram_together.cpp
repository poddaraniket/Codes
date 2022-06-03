#include<bits/stdc++.h>

using namespace std; 

vector<vector<string>> Anagrams(vector<string>& string_list) 
{
    map<string,int> umap;
   map<string,vector<string>> ans;
    for(int i=0;i<string_list.size();i++)
    {
     string s=string_list[i];
     sort(s.begin(),s.end());
     if(umap.find(s)!=umap.end())
      {
         ans[s].push_back(string_list[i]);
      }
     else
      {
         umap[s]++;
         ans[s].push_back(string_list[i]);
      }
    }  
     vector<vector<string>> v;
     for(auto it=ans.begin();it!=ans.end();it++)
      {
         v.push_back(it->second);
      }
    return v; 
}

int main()
{
  int t;
  cin>>t;
  while(t--)
  {
   int i,j,n;
   cin>>n;
   vector<string> string_list(n);
   for(i=0;i<n;i++)
     cin>>string_list[i];
   vector<vector<string>> result=Anagrams(string_list);
   for(i=0;i<result.size();i++)
   {
      for(j=0;j<result[i].size();j++)
       {
        cout<<result[i][j]<<" ";
       }
     cout<<endl;
   }
  }
}
