string FirstNonRepeating(string A){
		    // Code here
		    queue<char> q;
		    string temp="";
		    vector<int> vis(26,0);
		    
		    int n=A.length();
		    //cout<<a[A[0]-'a']<<endl;
		    for(int i=0;i<n;i++)
		    {
		        //pushing it in queue
		        //cout<<"*"<<endl;
		        //cout<<A[i]<<endl;
		        vis[A[i]-'a']++;
		        //cout<<a[A[i]-'a']<<endl;
		        if(vis[A[i]-'a']==1)
		         {
		             //cout<<"*"<<endl;
		             q.push(A[i]);
		         }
		        //what to enter in temp
		        // q.front() always entered in temp
		        while(!q.empty() && vis[q.front()-'a']>1)
		          {
		             // cout<<vis[q.front()-'a']<<endl;
		              q.pop();
		          }
		        if(q.empty())
		         {
		            temp+='#';
		         }
		        else
		         {
		             temp+=q.front();
		         }
		    }
		    return temp;
		}