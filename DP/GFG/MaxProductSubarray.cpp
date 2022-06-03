#include<bits/stdc++.h>
using namespace std;

int maxProduct(vector<int>& nums) {
      int ans=nums[0],curr_max=nums[0],prev_max=nums[0],prev_min=nums[0],curr_min=nums[0];
      for(int i=1;i<nums.size();i++)
      {
         curr_max=max(prev_max*nums[i],max(prev_min*nums[i],nums[i]));
         curr_min=min(prev_max*nums[i],min(prev_min*nums[i],nums[i]));
         ans=max(ans,curr_max); 
         prev_max=curr_max;
         prev_min=curr_min;
      }
      return ans;  
    }

int main()
{
   int t;
   cin>>t;
   while(t--)
   {
      int n;
      cin>>n;
      vector<int> v(n);
      for(int i=0;i<n;i++)
       cin>>v[i];
      cout<<maxProduct(v)<<endl;
       
   }
}    