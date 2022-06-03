//O(NlogN)

class Solution {
public:
    
    bool isPossible(int val,vector<int>& candies,long long k){
        long long count=0;
        for(int i=0;i<candies.size();i++){
            count+=(candies[i]/val);
        }
        if(count>=k){
            return true;
        }
        return false;
    }
    
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum=0;
        for(int i=0;i<candies.size();i++){
            sum+=candies[i];
        }
        if(sum<k){
            return 0;
        }
        int low=1,high=sum/k,best=0;
        while(low<=high){
            int mid=(low+high)/2;
            if(isPossible(mid,candies,k)){
                best=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return best;
    }
};