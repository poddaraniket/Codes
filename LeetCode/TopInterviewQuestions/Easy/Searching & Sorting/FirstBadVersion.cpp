// The API isBadVersion is defined for you.
// bool isBadVersion(int version);


//O(logN)
class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        int best=-1;
        while(l<=r){
            int m=r-(r-l)/2;
            if(isBadVersion(m)){
                best=m;
                r=m-1;
            }else{
                l=m+1;
            }
        }
        return best;
    }
};