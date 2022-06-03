int findSubstring(string s){
        vector<int> map(128,0);
        int counter; // check whether the substring is valid
        int begin=0, end=0; //two pointers, one point to tail and one  head
        int d; //the length of substring

        for() { /* initialize the hash map here */ }

        while(end<s.size()){

            if(map[s[end++]]-- ?){  /* modify counter here */ }

            while(/* counter condition */){ 
                 
                 /* update d here if finding minimum*/

                //increase begin to make it invalid/valid again
                
                if(map[s[begin++]]++ ?){ /*modify counter here*/ }
            }  

            /* update d here if finding maximum*/
        }
        return d;
  }class Solution {
public:
    vector<int> countBits(int num) {
       vector<int> ans;
       ans.push_back(0);
       if(num==0)
          return ans;
       ans.push_back(1); 
       if(num==1)
        {
           return ans;
        }
       int power=0; 
       for(int i=2;i<=num;i++)
        {
           if(ceil(log2(i))==floor(log2(i)))
            {
               ans.push_back(1);
               power=i;
            }
           else
           {
               int sum=ans[power]+ans[i-power];
               ans.push_back(sum);
           }
        }
       return ans; 
    }
};