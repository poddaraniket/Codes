class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
       int n=nums.size(); 
       //cout<<n<<endl; 
       if(n==1)
           return 1;
       int lis[2000];
       int count[2000];
       // memset(lis,1,sizeof(lis)); 
       // memset(count,1,sizeof(count));
       for(int i=0;i<nums.size();i++)
       {
           count[i]=1;
           lis[i]=1;
       }
       for(int i=1;i<nums.size();i++)
        {
           for(int j=0;j<i;j++)
           {
               if(nums[i]>nums[j])
               {
                   if(lis[i]<lis[j]+1)
                   {
                     lis[i]=lis[j]+1;
                       count[i]=count[j];
                   }
                   else if(lis[i]==lis[j]+1)
                   {
                       count[i]+=count[j];
                   }
               }
           }
        }
       int max=0,ans; 
       for(int i=0;i<nums.size();i++)
        {
           //cout<<count[i]<<" ";
           if(max<lis[i])
           {
               max=lis[i];
               ans=count[i];
           }
           else if(max==lis[i])
               ans+=count[i];
        }
      // cout<<endl; 
       return ans; 
    }
};