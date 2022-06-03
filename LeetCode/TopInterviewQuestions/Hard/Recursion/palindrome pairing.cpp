/*
     left string
  ----------------  (i,s.length)
palidrome substring

         (0,0)    .                
                -----  
                b,a,a
                  \
          (0,1)    \
                     a          .  
                   -----      -----
                    b,a       b,aa
                      \       /
            (0,2)      \  aa /    (1,2)
                         ---  
                          b 
                      (0,3) \       
                              baa



// Here you take a prefix if its palidrome then put that in the list and ceck for rest of the string 


*/



class Solution {
public:
    
    bool isPalindrome(string s){
        int l=0,r=s.length()-1;
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    
    void partitionUtil(vector<vector<string>> &ans,vector<string> &vec,string s){
      //  cout<<s<<endl;
        if(s.length()==0){
            if(vec.size()>0){
                ans.push_back(vec);
            }
            return;
        }
        for(int i=0;i<s.length();i++){
            string prefix=s.substr(0,i+1);
           // cout<<prefix<<endl;
            string rest=s.substr(i+1);
            if(isPalindrome(prefix)){
                // cout<<prefix<<" "<<rest<<endl;
                vec.push_back(prefix);
                partitionUtil(ans,vec,rest);
                vec.pop_back();
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> vec;
        partitionUtil(ans,vec,s);
        return ans;
    }
};