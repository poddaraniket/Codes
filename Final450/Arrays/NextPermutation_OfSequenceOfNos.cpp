

int binarySearch(vector<int> a,int low,int high,int val){
  //  cout<<"*"<<endl;
    if(high==low)
        return low;
   // cout<<val<<endl;
    int index;
    while(low<high){
        int mid=(low+high)/2;
        if(val<a[mid]){
            //cout<<mid<<endl;
            if(val>=a[mid+1]){
                index=mid;
                break;
            }else{
                low=mid+1;
            }
        }
        else{
            high=mid-1;
        }
    }
    if(low==high)
        return low;
    return index;
}

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        bool permute=false;
        for(int i=nums.size()-1;i>0;i--){ //O(n)
            if(nums[i]>nums[i-1]){
                int index=binarySearch(nums,i,nums.size()-1,nums[i-1]);   //O(logn)
               // cout<<index<<endl;
                swap(nums[i-1],nums[index]);
                sort(nums.begin()+i,nums.end());   O(nlogn)
                permute=true;
                break;
            }
        }
        if(!permute){
            sort(nums.begin(),nums.end());
        }
    }
};