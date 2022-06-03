//O(9*k)

class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> v;
        string s="123456789";
        string temp;
        temp=to_string(low);
        int l=temp.length();
        temp=to_string(high);
        int h=temp.length();
        for(int k=l;k<=h;k++){
            string val=s.substr(0,k);
            if(stoi(val)>high)
              break;
            for(int i=k;i<=s.length();i++){
                if(stoi(val)>=low && stoi(val)<=high)
                    v.push_back(stoi(val));
                val.erase(val.begin());
                val.push_back(s[i]);
            }
        }
       return v;
    }
};