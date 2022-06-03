#include<bits/stdc++.h>
using namespace std;

bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int i=0;i<nums.size();i++)
            sum+=nums[i];
        //cout<<sum<<endl;
        if((sum%2)==1)
            return false;
        bool dp[nums.size()+1][sum/2+1];
        for(int i=0;i<=nums.size();i++)
            dp[i][0]=true;
        for(int i=1;i<=sum/2;i++)
            dp[0][i]=false;
        for(int i=1;i<=nums.size();i++)
        {
            for(int j=1;j<=sum/2;j++)
            {
                if(j<nums[i-1])
                    dp[i][j]=dp[i-1][j];
                else
                    dp[i][j]=(dp[i-1][j-nums[i-1]] || dp[i-1][j]); 
            }
        }
        return dp[nums.size()][sum/2];
    }


int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
         cin>>nums[i];
        cout<<canPartition(nums)<<endl; 
    }
}