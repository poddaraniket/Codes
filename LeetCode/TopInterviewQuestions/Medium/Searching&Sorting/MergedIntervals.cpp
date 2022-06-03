//O(NlogN)

class Solution {
public:
    
    static bool cmp(vector<int> a,vector<int> b){
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result;
        int val=intervals[0][1];
        vector<int> v;
        v.push_back(intervals[0][0]);
        for(int i=1;i<intervals.size();i++){
            int val2=intervals[i][1];
            if(val>=intervals[i][0]){
                if(val<intervals[i][1]){
                    val=intervals[i][1];
                }
            }else{
                v.push_back(val);
                result.push_back(v);
                v.clear();
                v.push_back(intervals[i][0]);
                val=intervals[i][1];
            }
        }
        v.push_back(val);
        result.push_back(v);
        return result;
    }
};