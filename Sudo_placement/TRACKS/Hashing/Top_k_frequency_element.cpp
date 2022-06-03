#include<bits/stdc++.h>

using namespace std;

bool sortbydesc(pair<int,int> a,pair<int,int> b)
{
    if(a.second!=b.second)
     return a.second>b.second;
    else
     return a.first>b.first;
}

vector<int> TopK(vector<int>& array, int k) 
{
    map<int,int> mp;
    vector<pair<int,int>> v;
    for(int i=0;i<array.size();i++)
     mp[array[i]]++;
    for(auto it=mp.begin();it!=mp.end();it++)
     {
        v.push_back(make_pair(it->first,it->second)); 
     }
    sort(v.begin(),v.end(),sortbydesc); 
    vector<int> vec;
    for(int i=0;i<k;i++)
     vec.push_back(v[i].first);
    return vec; 
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++)
         {
           int num;
           cin>>num;
           v.push_back(num);
         }
        int k;
        cin>>k;
        vector<int> result=TopK(v,k);
        for(int i=0;i<result.size();i++)
         cout<<result[i]<<" ";
        cout<<endl;  
    }
}