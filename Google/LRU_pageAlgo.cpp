#include <bits/stdc++.h>
using namespace std;

void pageFaults(int pages[],int n,int cap)
{
    int pf=0;
    unordered_map<int,int> mp;
    vector<int> v;
    for(int i=0;i<n;i++)
     {
        if(v.size()<cap)
         {
            if(mp.find(pages[i])==mp.end())
             {
                pf++; 
                v.push_back(pages[i]);  
             }
            mp[pages[i]]=i;
         }
        else
         {
            if(mp.find(pages[i])==mp.end())
             {
                pf++; 
                int mini=n+1,loc,j; 
                for(j=0;j<v.size();j++)
                 {
                    if(mini>mp[v[j]])
                     {
                        mini=mp[v[j]]; 
                        loc=j;
                     }
                 }
                v[j]=pages[i];
             }
            mp[pages[i]]=i; 
         }
     }
    cout<<pf<<endl; 
}

int main() 
{ 
    int pages[] = {7, 0, 1, 0, 2, 3, 0, 4, 2, 3, 0, 3, 2}; 
    int n = sizeof(pages)/sizeof(pages[0]); 
    int capacity = 4; 
    pageFaults(pages, n, capacity); 
    return 0; 
} 
