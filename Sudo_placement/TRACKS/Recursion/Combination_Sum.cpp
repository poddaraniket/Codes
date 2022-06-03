#include <bits/stdc++.h>
using namespace std;

//vector<int> vec;

void add(vector<int> A,int sum,vector<vector<int>>&res,vector<int> &v,int index)
{
  cout<<"*"<<sum;
    if(sum==0)
    {
        res.push_back(v);
        return;  // this helps to backtrack,its return means going to the place where it was called.i.e to (1)
    }
    if(sum<0)
     return;
    while(index<A.size() && sum-A[index]>=0)
    {
        v.push_back(A[index]);
        add(A,sum-A[index],res,v,index); //(*16*0*14*0*12*0*10*0*8*0*6*0*4*0*2*0*0*0*1*1*0*2*3*1*2*2*1*3*5*1*0*1*4*2*3*3*7*1*2*1*1*2*0*3*6*2*0*2*5*3*9)----(1)
        index++;
        v.pop_back();
    }
}

vector<vector<int>> combinationsum(vector<int> &A,int B)
{
   set<int> a;
   for(i=0;i<A.size();i++)
    a.insert(A[i]);
   vector<int> v;    
   for(auto it=a.begin();it!=a.end();it++)
    {
       v.push_back(*it);
    }
    sort(v.begin(),v.end());
    vector<int> vec;
    vector<vector<int>> res;
    add(v,B,res,vec,0);
    return res;
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
       int x;
       cin>>x;
       v.push_back(x);
      }
     int sum;
     cin>>sum;
     vector<vector<int>> result;
     result=combinationsum(v,sum);
     for(i=0;i<result.size();i++)
      {
       for(j=0;j<result[i].size();j++)
       {
        cout<<result[i][j]<<" ";
       }
       cout<<endl;
      }
   }
	return 0;
}