//O(log(n+m))

class Solution {
public:
    
    double median(vector<int>& nums1, vector<int>& nums2){
        int n=nums1.size();
        int m=nums2.size();
        int l=0,r=n;
        while(l<=r){
            int partitionX=(l+r)/2;
            int partitionY=(n+m+1)/2-partitionX;
            
            int maxLeftX=(partitionX==0)?INT_MIN:nums1[partitionX-1];
            int minRightX=(partitionX==n)?INT_MAX:nums1[partitionX];
            
            int maxLeftY=(partitionY==0)?INT_MIN:nums2[partitionY-1];
            int minRightY=(partitionY==m)?INT_MAX:nums2[partitionY];
            
            if(maxLeftX<=minRightY && maxLeftY<=minRightX){
                if((n+m)%2!=0)
                   return (double)max(maxLeftX,maxLeftY); 
                else{
                    return ((double)max(maxLeftX,maxLeftY) + (double)min(minRightX,minRightY)) /2.0; 
                }
            }
            else if(maxLeftX>minRightY){
                r=partitionX-1;
            }else{
                l=partitionX+1;
            }
        }
        return 0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n<m)
            return median(nums1,nums2);
        else
            return median(nums2,nums1);
    }
};