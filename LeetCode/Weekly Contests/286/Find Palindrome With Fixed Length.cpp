// find queries[i]th smallest first half and reverse the first ha;f to get second half and combine both to get palidrome

class Solution {
public:
    vector<long long> kthPalindrome(vector<int>& queries, int intLength) {
        int n=(intLength+1)/2;
        int start=pow(10,n-1);
        int end=pow(10,n)-1;
        int totalCount=end-start+1;
        vector<string> v;
        for(int i=0;i<queries.size();i++){
            if(queries[i]>totalCount){
                v.push_back("-1");
            }
            else{
               int val=start+(queries[i]-1);
               v.push_back(to_string(val)); 
            }
        }
        for(int i=0;i<v.size();i++){
            if(v[i]=="-1")
                continue;
            string s=v[i].substr(0,intLength-n);
            reverse(s.begin(),s.end());
            v[i]+=s;
        }
        vector<long long> ans;
        for(int i=0;i<v.size();i++){
            ans.push_back((long long)stoll(v[i]));
        }
        return ans;
    }
};