// instead of using left and right array to store left and right min for a bar 
// we need to do that whike traversing it at once
long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long > s;
        long long area=0,maxarea=-1,i;
        for(i=0;i<n;)
         {
             
             if(s.empty() || arr[s.top()]<=arr[i])
              s.push(i++);
             else{
                 // since i is smaller than top(poped in 16) so right min for that top is i 
                 // and next top after removing this will be my left min 
                 int index=s.top();
                 s.pop();
                 if(s.empty())
                  area=arr[index]*i;
                 else
                  area=arr[index]*(i-s.top()-1);
             }
            maxarea=max(maxarea,area);     
         }
       // cout<<i<<endl; 
        while(!s.empty())
         {
            long long index=s.top();
            s.pop();
            if(s.empty())
              area=arr[index]*i;
            else
              area=arr[index]*(i-s.top()-1);
            maxarea=max(maxarea,area);   
         }
        return maxarea;   
    }