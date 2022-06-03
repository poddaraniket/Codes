//O(N)

void Equalizelength(string &A, string &B)
     {
        int a=A.length();
        int b=B.length();
        int diff=abs(a-b);
        string zeroes="";
        for(int i=0;i<diff;i++)
         zeroes+='0';
        if(a<b)
         A=zeroes+A;
        else
         B=zeroes+B; 
     }
     
	string addBinary(string A, string B)
	{
	    // your code here
	    // Making length of both strings equal
	    Equalizelength(A,B);
	    string ans; 
	    int carry=0; 
	    int n=A.length();
	    for(int i=n-1;i>=0;i--)
	     {
	         if(A[i]=='1' && B[i]=='1')
	          {
	              if(carry==0)
	               ans.push_back('0');
	              else
	               ans.push_back('1');
	              carry=1;    
	          }
	         else if(A[i]=='0' && B[i]=='0')
	          {
	             if(carry==1)
	                ans.push_back('1');
	              else
	                ans.push_back('0');
	              carry=0;    
	          }
	         else
	          {
	             // carry will remain same as how it came
	             if(carry==1)
	               ans.push_back('0');
	              else
	               ans.push_back('1');
	          }
	     }
	    if(carry==1)
	     ans.push_back('1');
	    reverse(ans.begin(),ans.end()); 
	    int index = 0;
        while (index + 1 < ans.length() && ans[index] == '0')
          index++;
	    return ans.substr(index); 
	}