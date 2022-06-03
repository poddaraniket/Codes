int minValue(string s, int k){
        // code here
        priority_queue<int>pq;
        vector<int> v(26,0);
        for(int i=0;i<s.length();i++)
         {
            v[s[i]-'a']++;
         }
        for(int i=0;i<26;i++)
         {
             if(v[i]!=0)
               pq.push(v[i]);
         }
        // while(!pq.empty())
        //  {
        //     int val=pq.top();
        //     cout<<val<<endl;
        //     //sum+=(val*val);
        //     pq.pop();
        //  } 
        while(k--)
         {
            int val=pq.top();
            pq.pop();
            val--;
            pq.push(val);
         }
        int sum=0; 
        while(!pq.empty())
        {
            int val=pq.top();
            sum+=(val*val);
            //cout<<val<<endl;
            pq.pop();
        }
        return sum;
    }