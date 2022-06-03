//O(N)

class Solution {
public:
    
    //QuickSelect -> O(N)
    int sort(vector<int> &nums,int low,int high,int k){
        // cout<<low<<" "<<high<<endl;
        if(low==high)
            return nums[low];
        int index=high;
        // cout<<index<<endl;
        index=partition(nums,index,low,high);
        if(index<k){
            return sort(nums,index+1,high,k);
        }else if(index>k)
            return sort(nums,low,index-1,k);
        else
            return nums[index];  //index=k
    }
    
    int partition(vector<int> &nums,int index,int low,int high){
        int val=nums[index];
        int j=low-1;
        for(int i=low;i<high;i++){
            if(nums[i]<=val){
                j++;
                swap(nums[j],nums[i]);
            }
        }
        j++;
        swap(nums[j],nums[high]);
        return j;
    }
    
    void wiggleSort(vector<int>& nums) {
         int n=nums.size();
         int mid=(nums.size()+1)/2;
         int median=sort(nums,0,n-1,mid);
         cout<<median<<endl;
         vector<int>temp(n,0);
         int s=0,e=n-1;
         for(int i=0;i<n;i++){
             if(nums[i]<median)
                 temp[s++]=nums[i];
             else if(nums[i]>median)
                 temp[e--]=nums[i];
         }
         while(s<mid)
             temp[s++]=median;
         while(e>=mid){
             temp[e--]=median;
         }
         int small=mid-1;
         int large=n-1; 
         for(int i=0;i<n;i++){
             if(i%2==0){
                 nums[i]=temp[small--];
             }else
                 nums[i]=temp[large--];
         }
    }
};