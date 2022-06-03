void f(vector<int>& one, int& n) {
    if(one.back() == (n-1))     one.pop_back();
    else {
        int more = n - 1 - one.back();
        int curr = one.back() + 1;

        one.pop_back();
        for(int i = 0;i<more;i++)
            one.push_back(curr ++);
    }
}
vector<int> solve(string s, vector<string> req) {
    vector<int> one;int curr = 0;
    vector<int> ans;
    int n = s.size();
    for(auto it : s) {
        if(it == '1')
            one.push_back(curr);
        curr ++;
    }
    for(auto it: req) {
        if(it == "?")   ans.push_back(one.size());
        else    f(one, n);
    }
    return ans;
} 