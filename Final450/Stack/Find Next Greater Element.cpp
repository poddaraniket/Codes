vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        vector<long long> v(n);
        stack<long long> s;
        for(int i=n-1;i>=0;i--){
            while(!s.empty())
            {
                if(arr[i]>s.top())
                 s.pop();
                else{
                   //s.push(arr[i]);    
                   break; 
                }
            } 
            if(s.empty()){
                s.push(arr[i]);
                v[i]=-1;
            }else{
                v[i]=s.top();
                s.push(arr[i]);
            }
        }
        return v;
    }