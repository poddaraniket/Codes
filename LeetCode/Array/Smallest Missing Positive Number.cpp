class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
       int j=0; 
       if(nums.size()==0)
           return 1;
       for(int i=0;i<nums.size();i++)
        {
          if(nums[i]<=0)
           {
            swap(nums[i],nums[j]);
            j++;  
           }     
        }
       int size=nums.size();  
       for(int i=0;i<nums.size()-j;i++)
        {
           if(abs(nums[i+j])-1<nums.size()-j && nums[abs(nums[i+j])-1+j]>0)
           {
               //cout<<nums[i+j]<<endl;
               nums[abs(nums[i+j])-1+j]=-nums[abs(nums[i+j])-1+j]; 
               //cout<<nums[abs(nums[i+j])-1+j]<<endl;
           }   
        }
       cout<<endl;  
       //int i; 
       for(int i=0;i<nums.size()-j;i++)
        {
           if(nums[i+j]>0)
           {
             //cout<<nums[i+j]<<endl;  
             return i+1;  
           }     
        }
       //cout<<"*"<<endl;
       return nums.size()-j+1; 
    } 
};