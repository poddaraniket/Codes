//O(N)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        //O(N)
        for(int i=nums.size()-1;i>=1;i--){
            if(nums[i]>nums[i-1]){
                index=i-1;
                break;
            }
        }
        cout<<index<<endl;
        int point=0;
        if(index!=-1){
            int val=nums[index];
            int low=index+1,high=nums.size()-1;
            int best;
            //O(logN)
            while(low<=high){
                int mid=(low+high)/2;
                if(nums[mid]>val){
                    best=mid;
                    low=mid+1;
                }else{
                    high=mid-1;
                }
            }
            swap(nums[best],nums[index]);
            point=index+1;
        }
        int left=point,right=nums.size()-1;
        //O(N)
        while(left<right){
            swap(nums[left++],nums[right--]);
        }
        // sort(nums.begin()+point,nums.end());
    }
};