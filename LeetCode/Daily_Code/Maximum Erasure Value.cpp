//O(N)

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int,int> freq;
        int sum=0,l=0,r=0,maxi=0;
        while(r<nums.size()){
            // cout<<freq[nums[r]]<<endl;
            freq[nums[r]]++;
            sum+=nums[r];
            // cout<<freq[nums[r]]<<endl;
            while(freq[nums[r]]>1){
                // cout<<nums[l]<<endl;
                freq[nums[l]]--;
                sum-=nums[l];
                l++;
            }
            maxi=max(maxi,sum);
            r++;
        }
        return maxi;
    }
};