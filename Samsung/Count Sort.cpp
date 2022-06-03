// Count Sort  -> Used for sorting lareg amount of numbers when the crange of numbers present is less 
// eg-> sort ranki list of JEE (Range of Number 0-360)
// Why Can't we just use te freq to place te value -> bcoz count sort needs to be stable sort
// Stable Sot-> when sorting is the value is same then those keys will be sorted as per there position



string countSort(string arr){
        // code here
        int freq[26]={0};
        for(int i=0;i<arr.length();i++)
         freq[arr[i]-'a']++;
        for(int i=1;i<26;i++)
         freq[i]+=freq[i-1];
        for(int i=0;i<26;i++)
         freq[i]-=1;
        vector<char> v(arr.length()); 
        for(int i=arr.length()-1;i>=0;i--)
         {
            v[freq[arr[i]-'a']]=arr[i];
            freq[arr[i]-'a']--;
         }
        string ans=""; 
        for(int i=0;i<arr.length();i++)
         {
            ans+=v[i]; 
         }
        return ans; 
    } 