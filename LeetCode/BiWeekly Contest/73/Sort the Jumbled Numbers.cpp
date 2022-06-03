// nums.size() -> N (1 , 3 * 10^4)
// nums[i].length() -> M (0 , 9)


//O(NlogN)

class Solution {
public:
    
    static bool cmp(pair<int,int> a,pair<int,int> b){
        if(a.second==b.second)
           return true;
        return a.first<b.first;
    }
    
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> ans;
        vector<string> v;
        
        //O(N)
        for(int i=0;i<nums.size();i++){
            v.push_back(to_string(nums[i]));
        }
        
        //O(N*M)
        for(int i=0;i<v.size();i++){  //O(N)
            string s=v[i];
            for(int j=0;j<s.length();j++){  //O(M)
                int index=s[j]-'0';
                int key=mapping[index];
                s[j]=(char)(key+'0');    
            }
           v[i]=s; 
        }
        vector<pair<int,int>> v1;
        //O(N)
        for(int i=0;i<v.size();i++){
            v1.push_back({stoi(v[i]),i});
        }
        //O(NlogN) 
        sort(v1.begin(),v1.end(),cmp); 
        //O(N)
        for(int i=0;i<v1.size();i++){
            ans.push_back(nums[v1[i].second]);
        }
       return ans; 
    }
};