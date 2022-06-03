//O(N^2)

class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int r=s.length()-1;
        int l=0;
        int count=0;
        while(l<r){
            int k=l; 
            // fiding the matching element
            while(s[k]!=s[r]){
                k++;
            }
            //swapping
            if(k==r){
                swap(s[k],s[k-1]);
                count++;
                continue;
            }
            else{
                while(k>l){
                  swap(s[k],s[k-1]);
                  count++;
                  k--;
                }
            }
            
           l++;
           r--;
        }
       return count; 
    }
};