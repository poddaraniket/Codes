long long minCost(long long arr[], long long n) {
        // Your code here
        priority_queue<long long,vector<long long>,greater<long long>> pq;
        for(int i=0;i<n;i++)
         {
             pq.push(arr[i]);
         }
        long long sum=0; 
        while(pq.size()>1)
         {
             long long frst=pq.top();
             pq.pop();
             long long second=pq.top();
             pq.pop();
             sum+=frst+second;
             pq.push(frst+second);
         }
        return sum; 
    }