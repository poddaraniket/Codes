/*
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        bool changed=false;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]<=nums[i+1])
                continue;
            if(changed)
                return false;
            // change the value
            // 1. increase  the value 
            if(i==0 || nums[i+1]>=nums[i-1]){
                nums[i]=nums[i+1];
            }
            // 2. decreaese the value 
            else{
                nums[i+1]=nums[i];
            }
            changed=true;
        }
        return true;
    }
};


*/












class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int noOfGreater=0,noOflesser=0;
        int maxi=0;
        for(int i=0;i<nums.size();i++){
            maxi=max(nums[i],maxi);
            if(nums[i]<maxi)
                noOfGreater++;
            // cout<<maxi<<endl;
            // if(noOfGreater>1)
            //     return false;
        }
        int mini=INT_MAX;
        for(int i=nums.size()-1;i>=0;i--){
            mini=min(nums[i],mini);
            if(nums[i]>mini)
                noOflesser++;
            // cout<<maxi<<endl;
            // if(noOfGreater>1)
            //     return false;
        } 
        return min(noOflesser,noOfGreater)>1 ? false : true;
    }
};