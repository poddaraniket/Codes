void topoSort(vector<int> adj[],int K,string &ans){
        int indegree[K]={0};
        for(int i=0;i<K;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int> q;
        for(int i=0;i<K;i++){
            if(indegree[i]==0){
                //cout<<i<<endl;
             q.push(i);
            }
        }
        while(!q.empty()){
            int src=q.front();
            //cout<<src<<endl;
            ans+=(char)(src+'a');
           // cout<<ans<<endl;
            q.pop();
            for(int i=0;i<adj[src].size();i++){
                indegree[adj[src][i]]--;
                if(indegree[adj[src][i]]==0)
                 q.push(adj[src][i]);
            }
        }
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<int> adj[K];
        
        // Create a graph that contains the what can come before what
        for(int i=0;i<N-1;i++){
            string w1=dict[i];
            string w2=dict[i+1];
            for(int j=0;j<min(w1.length(),w2.length());j++){
                if(w1[j]!=w2[j]){
                    //cout<<w1[j]<<" "<<w2[j]<<endl;
                    adj[w1[j]-'a'].push_back(w2[j]-'a');
                    break;
                }
            }
        }
        string ans="";
        topoSort(adj,K,ans);
       // cout<<ans<<endl;
        return ans;
    }