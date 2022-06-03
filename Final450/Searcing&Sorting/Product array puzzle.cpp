 vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here 
        int countZero=0;
        long long int totalPro=1;
        for(int i=0;i<n;i++){
           if(nums[i]==0)
             countZero++;
            else
             totalPro*=nums[i];
        }
        vector<long long int> v;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                if(countZero==1)
                  v.push_back(totalPro);
                else
                  v.push_back(0);
            }
            else{
                if(countZero>0)
                 v.push_back(0);
                else
                 v.push_back(totalPro/nums[i]);
            }
        }
        return v;
    }