#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> threeSum(vector<int>& nums) {
       set<pair<int,pair<int,int>>> st; 
       sort(nums.begin(),nums.end());
       int n=nums.size(); 
       vector<vector<int>> res;
      // int p=0; 
       for(int i=0;i<n;i++)
       {
           int a=nums[i];
           int l=i+1,r=n-1;
           while(l<r)
           {
               if(a+nums[l]+nums[r]==0)
                {
                  st.insert({a,{nums[l],nums[r]}});
                  l++;
                  r--;
                }
               else if(a+nums[l]+nums[r]>0)
                {
                   r--;
                } 
               else
                  l++; 
           }
       }
      //res.resize(p); 
      for(auto it=st.begin();it!=st.end();it++)
      {
          vector<int> v;
          v.push_back((*it).first);
          v.push_back((*it).second.first);
          v.push_back((*it).second.second);
          res.push_back(v);
      }
      return res;  
    }

    int main()
    {
      int n;
      cin>>n;
      vector<int> nums;
      for(int i=0;i<n;i++)
        cin>>nums[i];
      vector<vector<int>> res=threeSum(nums); 
      for(int i=0;i<res.size();i++)
      {
        for(int j=0;j<res[i].size();i++)
  			cout<<res[i][j]<<" ";
  		cout<<endl;	
      } 
    }