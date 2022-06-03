bool cmp(vector<int>a,vector<int>b){
        return a[0]<b[0];
    }
class Solution {
    
public: 
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        stack<pair<int,int>>s;
        sort(intervals.begin(),intervals.end(),cmp);
        s.push({intervals[0][0],intervals[0][1]});
        for(int i=1;i<intervals.size();i++){
            int a=s.top().first;
            int b=s.top().second;
            if(b<intervals[i][0]){
                s.push({intervals[i][0],intervals[i][1]});
            }
            else if(b<intervals[i][1]){
                s.pop();
                s.push({a,intervals[i][1]}); 
            } 
        }
        vector<vector<int>> vec;
        int i=0;
        while(!s.empty()){
            int a=s.top().first;
            int b=s.top().second;
            cout<<a<<" "<<b<<endl;
            s.pop();
            vector<int> v;
            v.push_back(a);
            v.push_back(b);
            vec.push_back(v);
        }
        //sort(vec.begin(),vec.end(),cmp);
        return vec;
    }
};