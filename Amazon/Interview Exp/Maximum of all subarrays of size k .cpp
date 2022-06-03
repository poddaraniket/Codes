 vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        // your code here
        deque<int> dq;
        vector<int> v;
        for(int i=0;i<k;i++)
         {
             // keeping values in queue in decresing order
             while(!dq.empty() && arr[dq.back()]<=arr[i]){
              dq.pop_back();
             }
             dq.push_back(i); 
         }
        for(int i=k;i<n;i++) 
         {
            v.push_back(arr[dq.front()]); 
            // removing indexes that don't lie in the window 
            while(!dq.empty() && dq.front()<=i-k){
              dq.pop_front();
            }
            while(!dq.empty() && arr[dq.back()]<=arr[i]){
              dq.pop_back();
            }
            dq.push_back(i); 
         }
        v.push_back(arr[dq.front()]); 
        return v; 
    }