//O(NlogN)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> LIS(n+1,10001);
        LIS[0]=-10001;
        for(int i=0;i<n;i++){
            int val=nums[i];
            int l=0,h=n-1,best;
            while(l<=h){
                int mid=(l+h)/2;
                if(LIS[mid]<val){
                    best=mid;
                    l=mid+1;
                }else{
                    h=mid-1;
                }
            }
            LIS[best+1]=val;
        }
        for(int i=n;i>=0;i--){
            if(LIS[i]!=10001)
                return i;
        }
        return 1;
    }
};