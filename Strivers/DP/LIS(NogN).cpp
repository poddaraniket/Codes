//O(NlogN)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
       vector<int> LIS(n+1,100001);
        LIS[0]=-100001;
        for(int i=0;i<n;i++){
            int low=0,high=n;
            int best;
            while(low<=high){
                int mid=(low+high)/2;
                if(LIS[mid]<nums[i]){
                    low=mid+1;
                    best=mid;
                }else{
                    high=mid-1;
                    // best=mid;
                }
            }
            // cout<<"*"<<endl;
           LIS[best+1]=nums[i]; 
        }
        for(int i=n;i>=1;i--){
            if(LIS[i]!=100001)
                return i;
        }
        return 1;
    }
};