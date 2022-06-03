//used deque to maintain the max and min list

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
      deque<int> inc,dec;
      int n=nums.size(); 
      inc.push_back(0);
      dec.push_back(0);
      int maxPoss=1; 
      int windowStart=0;  
      for(int windowEnd=1;windowEnd<nums.size();windowEnd++)
      {
          //cout<<"*"<<endl;
          while(!inc.empty())
           {
              //cout<<"inc"<<endl;
              int u=inc.back();
              if(nums[u]>nums[windowEnd])
                 inc.pop_back();
              else
              {
                break;  
              }  
           }
          inc.push_back(windowEnd);
          while(!dec.empty())
          {
             // cout<<"dec"<<endl;
              int u=dec.back();
              if(nums[u]<nums[windowEnd])
                 dec.pop_back();
              else
              {
                break;  
              }   
          }
         dec.push_back(windowEnd);
         while((nums[dec.front()]-nums[inc.front()])>limit)
          {
             if(dec.front()==windowStart)
                 dec.pop_front();
             if(inc.front()==windowStart)
                 inc.pop_front();
             windowStart++;
          }
         maxPoss=max(maxPoss,windowEnd-windowStart+1); 
      }
     return maxPoss;   
    }
};