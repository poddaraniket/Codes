vector<string> getShrunkArray(vector<string> &v, int k) {

    vector<string> shrunkArray;
    int n = v.size();
    stack<pair<string,int> > s;
    for(int i=0;i<n;i++) {
        string curr = v[i];
        if(!s.empty()) {
            if(s.top().first == curr) {
                s.top().second += 1;
            } else {
                if(s.top().second >= k) {
                    s.pop();
                    i--;
                } else {
                    s.push({curr, 1});
                }
            }
        } else {
            s.push({curr, 1});
        }
    }

    if(!s.empty() && s.top().second >= k) {
        s.pop();
    }

    while (!s.empty()) {
        pair<string, int> p = s.top();
        s.pop();
        for(int i=0;i<p.second;i++) {
            shrunkArray.push_back(p.first);
        }
    }

    reverse(shrunkArray.begin(), shrunkArray.end());
    return shrunkArray;
}