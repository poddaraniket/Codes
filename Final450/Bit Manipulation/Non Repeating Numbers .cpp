vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int n=nums.size();
        int xorSum=0;
        for(int i=0;i<n;i++)
         {
             xorSum^=nums[i];
         }
        int setBit=(xorSum)&~(xorSum-1);
        int a=0,b=0;
        for(int i=0;i<n;i++)
         {
             if(setBit&nums[i])
              a^=nums[i];
             else
              b^=nums[i];
         }
        vector<int> v; 
        v.push_back(min(a,b));
        v.push_back(max(a,b));
        return v;
    }