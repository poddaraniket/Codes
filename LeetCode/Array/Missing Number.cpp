// the number will be from 0 to n so we will have a 0 if number is missing
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int x1=0;
        int x2=0;
        for(int i=0;i<n;i++)
        {
            x2^=(i+1);
            x1^=nums[i];
        }
        return x1^x2;
    }
};