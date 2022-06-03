class Solution {
public:
    bool Partition(int start,vector<int>& nums,bool used[],int k,int target_sum,int sum)
    {
        if(k==1)
        {
            //cout<<"/"<<endl;
            return true;
        }
        if(sum==target_sum)
         {
//cout<<sum<<endl;
             return Partition(0,nums,used,k-1,target_sum,0); 
         }
        for(int i=start;i<nums.size();i++)
        {
            if(used[i]==false)
             {
                used[i]=true;
                if(Partition(i+1,nums,used,k,target_sum,sum+nums[i]))
                    return true;
                used[i]=false; 
             }
        }
       return false; 
    }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
     int sum=0;
     int size=nums.size();   
     bool used[100000]={false};   
     for(int i=0;i<nums.size();i++)
      {
         sum+=nums[i];
      }
     if(k==0 || sum%k!=0)
         return false;
      return Partition(0,nums,used,k,sum/k,0);
    }
};