class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        // update the result array as right iterated prduct
        vector<int> answers(n);
        answers[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            answers[i]=answers[i+1]*nums[i];
        }
        // update the original array as left iterated product
        for(int i=1;i<n;i++){
            nums[i]*=nums[i-1];
        }

        int first=answers[1];
        int last=nums[n-2];
        for(int i=1;i<n-1;i++)
        {
            answers[i]=nums[i-1]*answers[i+1];
        } 
        answers[0]=first;
        answers[n-1]=last;
        return answers;
    }
};