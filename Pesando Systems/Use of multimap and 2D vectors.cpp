#include <bits/stdc++.h>
using namespace std;

vector<vector<double>> duplicate(vector<vector<double>> vect)
{
   // cout<<"*"<<endl;
    multimap<double,pair<double,double>> mp;
    queue<pair<double,pair<double,double>>> q;
    //int n=vect.size();
    for(int i=0;i<vect.size();i++)
     {
        int f=0; 
        double id=vect[i][0];
        double start=min(vect[i][1],vect[i][2]);
        double end=max(vect[i][1],vect[i][2]);
       // cout<<id<<" "<<start<<" "<<end<<endl;
        for(auto it=mp.begin();it!=mp.end();it++)
         {
            //cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
            if(it->first==id && (it->second.first==start && it->second.second==end)) 
            {
             f=1;
             break;
            }
         }
        if(f==0)
        {
         q.push({id,{start,end}});
         mp.insert({id,{start,end}});
         //cout<<id<<endl;
        }
     }
    //cout<<q.size()<<endl; 
    vector<vector<double>> ans(q.size());
    for(int i=0;i<q.size();i++)
     {
        ans[i].resize(3); 
     }
    int p=0; 
    //cout<<"*"<<endl;
    while(!q.empty())
     {
        ans[p][0]=q.front().first;
        ans[p][1]=q.front().second.first;
        ans[p][2]=q.front().second.second;
        p++;
        //cout<<q.front().first<<" "<<q.front().second.first<<" "<<q.front().second.second<<endl;
        q.pop();
     }
    return ans; 
}

int main() {
	// your code goes here
	vector<vector<double>> vect{ { 1.0,2.5,1.5}, 
                               { 2.0, 1.0,2.0}, 
                               { 4.0,1.0,1.5,},
                               {2.0,2.5,1.5},
                               {1.0,1.5,2.5}};
    vector<vector<double>> ans=duplicate(vect);   
    for(int i=0;i<ans.size();i++)
     {
        for(int j=0;j<ans[i].size();j++)
         {
             cout<<ans[i][j]<<" ";
         }
        cout<<endl; 
     }
}
