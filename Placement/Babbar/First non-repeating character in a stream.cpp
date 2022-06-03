string FirstNonRepeating(string A){
		    // Code here
		    deque<char> dq;
		    int a[26]={0};
		    string ans="";
		    for(int i=0;i<A.length();i++){
		        a[A[i]-'a']++;
		        dq.push_back(A[i]);
		        while(!dq.empty())
		        {
		            char t=dq.front();
		            if(a[t-'a']<2)
		             break;
		            dq.pop_front(); 
		        } 
		       if(dq.empty())
		        ans+='#';
		       else
		        ans+=dq.front();
		    }
		    return ans;
		}