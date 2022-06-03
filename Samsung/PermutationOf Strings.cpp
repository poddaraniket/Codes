void find_permutationUtil(string s,int index,vector<string> &v)
	    {
	        if(index==s.length()-1)
	         {
	             v.push_back(s);
	             return;
	         }
	        for(int i=index;i<s.length();i++)
	         {
	             swap(s[i],s[index]);
	             find_permutationUtil(s,index+1,v);
	             swap(s[i],s[index]);
	         }
	    }
	
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string> vec;
		    find_permutationUtil(S,0,vec);
		    sort(vec.begin(),vec.end());
		    return vec;
		}