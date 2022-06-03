//O(NlogN)

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       set<long long> s; 
       for(int i=0;i<nums.size();i++){
          s.insert(nums[i]);           
       } 
        
       long long l=1;
       long long ans=0; 
       for(auto r : s){
           if(k==0)
              return ans;
           if(k>=(r-l))
              k-=(r-l);
           else
               break;
           ans+=(r*(r-1))/2 - (l*(l-1))/2;
           l=r+1;
       }
      long long end=l+k;
      ans+=(end*(end-1))/2 - (l*(l-1))/2;
      return ans;  
    }
};