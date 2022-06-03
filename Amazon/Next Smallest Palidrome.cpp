//O(N)

class Solution{
public:


    string increment(string s){
        int carry=1;
        for(int i=s.length()-1;i>=0;i--){
            int val=s[i]-48+carry;
            carry=val/10;
            int mod=val%10;
            s[i]=(char)mod+48; 
        }
        if(carry>0){
            char c=(char)carry+48;
            s=c+s;
        }
        return s;
    }
   
	vector<int> generateNextPalindrome(int num[], int n) {
	    // code here
	    string s="";
	    for(int i=0;i<n;i++){
	        s+=(char)num[i]+48;
	    }
	    if(s.length()==1 && stoi(s)<9){
	     int val=stoi(s)+1;
	     s=to_string(val);
	    }else if(s.length()>=1 && s.length()<=2 && stoi(s)<11){
	        s="11";
	    }else if(s==to_string(pow(10,s.length())-1)){
	        int val=stoi(s)+2;
	        s=to_string(val);
	    }
	    else if(s.length()%2==0){
	        int index=s.length()/2;
	        string left=s.substr(0,index);
	        string temp=left;
	        string right=s.substr(index);
	        reverse(left.begin(),left.end());
	        if(left<=right){
	            left=increment(temp);
	            temp=left;
	            reverse(left.begin(),left.end());
	        }
	        s=temp+left;
	    }else{
	        int index=s.length()/2;
	        string left=s.substr(0,index);
	        string temp=left;
	        char mid=s[index]; 
	        string right=s.substr(index+1);
	        reverse(left.begin(),left.end());
	        if(left<=right){
	            string left1=increment(temp+mid);
	            left=left1.substr(0,index);
	            temp=left;
	            mid=left1[index];
	            reverse(left.begin(),left.end());
	        s=temp+mid+left; 
	    }
	    vector<int> ans(s.length());
	    for(int i=0;i<s.length();i++){
	        ans[i]=s[i]-48;
	    }
	    return ans;
	}

};