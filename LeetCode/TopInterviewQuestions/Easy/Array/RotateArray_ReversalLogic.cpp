//O(N)   -> O(1)

class Solution {
public:
    
    void reverse(vector<int> &nums,int s,int e){
        while(s<e){
            swap(nums[s++],nums[e--]);
        }
    }
    
    void print(vector<int>& nums){
        int n=nums.size();
       for(int i=0;i<n;i++)
           cout<<nums[i]<<" ";
        cout<<endl; 
    }
    
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0)
           return;
        k%=n;
        reverse(nums,0,n-1);
        reverse(nums,0,k-1);
        reverse(nums,k,n-1);
    }
};