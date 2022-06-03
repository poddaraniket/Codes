class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        vector<int> v;
        v.push_back(1);
        ans.push_back(v);
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            int t=0;
            for(auto it : v){
                int sum=t+it;
                temp.push_back(sum);
                t=it;
            }
            temp.push_back(t);
            v=temp;
            ans.push_back(temp);
        }
        return ans;
    }
};