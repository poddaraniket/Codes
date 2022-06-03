class Solution {
public:
    
    long long numberOfWeeks(vector<int>& milestones) {
        long long maxi=0;
        long long sum=0;
        for(int i=0;i<milestones.size();i++){
            sum+=milestones[i];
            maxi=max(maxi,(long long)milestones[i]);
        }
        long long remainingElement=sum-maxi;
        if(remainingElement<=maxi-1)
            return 2* remainingElement +1;
        return sum;
    }
};