
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());      
        unordered_map<string,vector<string>> mp;
        for(string word : products){
            for(int i=1;i<=word.length();i++){
                string w=word.substr(0,i);
                if(mp[w].size()<3){
                    mp[w].push_back(word);
                }
            }
        }
        vector<vector<string>> v;
        string s="";
        for(char c: searchWord){
            s+=c;
            v.push_back(mp[s]);
        }
        return v;
    }
};  