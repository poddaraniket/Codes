//Binary Search (range based)
//O(Nlogk)  N->total busses k-> rage of time

class Solution {
public:
    
    bool isSafe(vector<int>& time, int totalTrips,long long feasibleTime){
        // cout<<feasibleTime<<"->";
        long long count=0;
        for(int i=0;i<time.size();i++){
            count+=(feasibleTime/(long long)time[i]);
            // cout<<count<<" ";
            if(count>=(long long)totalTrips)
                return true;
        }
        return false;
    }
    
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long mini=100000000;
        for(int i=0;i<time.size();i++){
            mini=min(mini,(long long)time[i]);
        }
        long long low=1,high=mini*totalTrips;
        long long mid=0,best;
        while(low<=high){
            mid=(high-low)/2 + low;
            if(isSafe(time,totalTrips,mid)){
                // cout<<endl;
                best=mid;
                // cout<<best<<endl;
                high=mid-1;
            }
            else{
                // cout<<endl;
                low=mid+1;
            }
        }
        return best;
    }
};