#include<bits/stdc++.h>

using namespace std;

void findSum(vector<int>& nums, int S,int index,int sum)
{
    if(index==nums.size())
     {
       if(sum==S)
         count++;
       return;
     }
    findSum(nums,S,index+1,sum+nums[index]);
    findSum(nums,S,index+1,sum-nums[index]);
}

int findTargetSumWays(vector<int>& nums, int S) 
{
    count=0;
    findSum(nums,S,0,0);
    return count;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,S;
        vector<int> nums(n);
        for(int i=0;i<n;i++)
         cin>>nums;
        cin>>S; 
        cout<<findTargetSumWays(nums,S)<<endl;
    }
}