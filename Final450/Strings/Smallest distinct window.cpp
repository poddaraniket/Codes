string findSubString(string str)
    {
        // Your code goes here 
        int vis[256]={0};
        int count=0;
        for(int i=0;i<str.length();i++){
            if(vis[str[i]]==0)
             count++;
            vis[str[i]]=1;
        }
        int v[256]={0};
        int start=0;
        int low=0,mini=str.length()+1;
        for(int high=0;high<str.length();high++){
            if(v[str[high]]==0){
                //cout<<str[high]<<endl;
                count--;
            }
            v[str[high]]++;
            if(count==0){
                while(v[str[low]]>1){
                    if(v[str[low]]>1)
                        v[str[low]]--;
                    low++;
                }
                if(mini>(high-low+1)){
                   // cout<<low<<endl;
                    start=low;
                    mini=high-low+1;
                }
                
            }
            
        }
//cout<<mini<<endl;    
       return str.substr(start,mini); 
    }