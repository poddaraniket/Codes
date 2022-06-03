vector<vector<string> > Anagrams(vector<string>& string_list) 
{
    // Your Code Here
    map<string,int> mp;
    map<string,vector<string>> ans;
    for(int i=0;i<string_list.size();i++){
        string s=string_list[i];
        sort(s.begin(),s.end());
        if(mp[s]==0){
            mp[s]++;
            ans[s].push_back(string_list[i]);
        }
        else{
            ans[s].push_back(string_list[i]);
        }
    }
    vector<vector<string>> v;
    for(auto it=ans.begin();it!=ans.end();it++){
        v.push_back(it->second);
    }
    return v;
}