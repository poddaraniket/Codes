// If the size of the vector is 1
// We can generalize that if the number of operations is odd, the vector will be empty and so we will return -1.
// If the number of operations is even then we will return the element.

// 2nd case :
// If the number of operations is greater than the vector size, then we can remove all the elements from the vector and add the highest elements.
// By generalizing this case, we can return the maximum element of the vector.

// 3rd case :
// If the number of operations is equal to the vector size, then we will remove the first (k-1) elements from the vector and add the maximum element from the removed elements to vector.
// So we will return the maximum element from the first (k-1) elements.

// 4th case :
// If the number of operations is less than vector size, then we will remove the first (k-1) elements from the vector and we have a option of removing the kth element from the vector or adding the maximum of removed (k-1) elements.
// By generalizing, the answer will be maximum element from the maximum element of first (k-1) elements and the (k+1)th element.

class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n=nums.size();
        // case 1 if(nums size is 1 ; k is odd -> empty && k is even that element remians)
       if(n==1 && k%2==1)
           return -1;
       int maxi=-1; 
       for(int i=0;i<n && i<k-1 ;i++){
           maxi=max(maxi,nums[i]);
       }
       //kth step either u add(if the element removed had the highest value ) or remove(if the next element will be the highest) so   
       if(k<n){
           maxi=max(maxi,nums[k]);
       } 
       return maxi; 
    }
};