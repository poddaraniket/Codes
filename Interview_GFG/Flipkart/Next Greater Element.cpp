 vector<long long> nextLargerElement(vector<long long> arr, int n){
        // Your code here
        stack<long long> st;
        vector<long long> v;
        for(int i=arr.size()-1;i>=0;i--)
         {
             while(!st.empty() && st.top()<arr[i])
              st.pop();
             if(st.empty())
              v.push_back(-1);
             else
              v.push_back(st.top());
             st.push(arr[i]); 
         }
        reverse(v.begin(),v.end()); 
        return v; 
    }