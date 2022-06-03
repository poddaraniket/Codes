//O(LogN)

class Solution {
public:
    int mySqrt(int x) {
        int low=0,high=x,best=1;
        while(low<=high){
            int mid=(low+high)/2;
            if((long long int)mid*mid > (long long int)x){
                high=mid-1;
            }else{
                best=mid;
                low=mid+1;
            }
        }
       return best; 
    }
};