void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l1=m-1,l2=n-1,l=nums1.size()-1;
        while(l2>=0){
            if(l1>=0 && nums1[l1]>nums2[l2])
               nums1[l--]=nums1[l1--];
            else
                nums1[l--]=nums2[l2--];
        }
    }