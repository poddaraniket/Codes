void combo(string s,vector<string> &v,string temp)
	    {
	        if(s.length()==0){
	         v.push_back(temp);
	         return;
	        }
	        combo(s.substr(1),v,temp+s[0]);
	        combo(s.substr(1),v,temp);
	    }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    		    vector<string> v;
		    if(s.length()==1){
		     v.push_back(s);
		     return v;
            }
		    combo(s,v,"");
		    sort(v.begin(),v.end());
		    return v;
		}
}


// vector<string> AllPossibleStrings(string s){
// 		    // Code here
// 		    vector<string> v;
// 		    unsigned setsize=pow(2,s.length());
// 		    for(int i=0;i<setsize;i++) 
// 		    {
// 		        string temp="";
// 		        for(int j=0;j<s.length();j++) 
// 		        {
// 		            if(i & (1<<j))
// 		              temp+=s[j];    
// 		        }
// 		        v.push_back(temp);
// 		    }
// 		    sort(v.begin(),v.end());
// 		    return v;
// 		}