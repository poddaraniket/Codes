long long countPairs(int N, int X, vector<int> numbers){
        // code here
        long long count;
        unordered_map<string,int> mp;
        for(int i=0;i<N;i++){
            mp[to_string(numbers[i])]++;
        }
        string s=to_string(X);
        int len=s.length();
        int cnt=0;
        for(int i=0;i<N;i++)
         {
             mp[to_string(numbers[i])]--;
             string s1=to_string(numbers[i]);
             int l1=s1.length();
             if(s.substr(0,l1)==s1)
              {
                  cnt+=mp[s.substr(l1)];
              }
             mp[to_string(numbers[i])]++; 
         }
        return cnt; 
    }