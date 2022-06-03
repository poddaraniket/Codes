static bool cmp(int a,int b)
     {
        return a>b; 
     }
    
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
        vector<int> v;
        sort(candies,candies+N);
        int minCost=0,s=0,e=N-1;
        while(s<=e)
         {
            minCost+=candies[s];
            s++;
            e=e-K;
         }
        v.push_back(minCost); 
        sort(candies,candies+N,cmp);
        int maxCost=0;
        s=0;
        e=N-1;
        while(s<=e)
         {
            maxCost+=candies[s];
            s++;
            e=e-K;
         }
        v.push_back(maxCost);  
        return v;
    }