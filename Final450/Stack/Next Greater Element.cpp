vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> nge(n);
        stack<long long> s;
        s.push(arr[n-1]);
        nge[n-1]=-1;
        for(int i=n-2;i>=0;i--)
        {
            while(!s.empty() && s.top()<=arr[i])
             {
                 s.pop();
             }
            if(s.empty())
             nge[i]=-1;
            else
             nge[i]=s.top();
            s.push(arr[i]); 
        }
        return nge;
    }