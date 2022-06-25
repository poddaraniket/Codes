/*
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]


*/


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n==0)
            return;
        int l1=m-1,l2=n-1,l=nums1.size()-1;
        while(l2>=0){
            if(l1>=0 && nums1[l1]>=nums2[l2]){
                nums1[l--]=nums1[l1--];
            }else{
                nums1[l--]=nums2[l2--];
            }
        }
    }
};