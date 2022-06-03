//O(N^2)  O(N^2)

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        map<int,int> mp1,mp2;
        int sum;
        for(int i=0;i<nums1.size();i++){
            for(int j=0;j<nums2.size();j++)
            {
               sum=nums1[i]+nums2[j]; 
               mp1[sum]++;  
            }
        }
        
        for(int i=0;i<nums3.size();i++){
            for(int j=0;j<nums4.size();j++)
            {
               sum=nums3[i]+nums4[j]; 
               mp2[sum]++;  
            }
        }
        int count=0;
        for(auto val1 : mp1)
        {
            int needed=-(val1.first);
            count+=(val1.second)*mp2[needed];
        }
        return count;
    }
};