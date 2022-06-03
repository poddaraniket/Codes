class Solution {
public:
    int characterReplacement(string s, int k) {
     int n=s.length();
     //cout<<n<<endl;   
     int letters[27]={0};
     long long int window_start=0;
     long long int max_length=0,max_count=0;   
     for(int window_end=0;window_end<n;window_end++)
      {
         letters[s[window_end]-'A']++;
         long long int curr_count=letters[s[window_end]-'A'];
         max_count=max(max_count,curr_count);
         while(window_start<=window_end && window_end-window_start-max_count+1>k)
          {
             letters[s[window_start]-'A']--;
             window_start++;
          }
         max_length=max(max_length,window_end-window_start+1);
      }
     return max_length;   
    }
};