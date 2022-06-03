// O(n)

int minThrow(int N, int arr[]){
        // code here
        int board[31];
        memset(board,-1,sizeof(board));
        for(int i=0;i<2*N;i+=2)
         {
            board[arr[i]]=arr[i+1];
         }
        // for(int i=0;i<31;i++)
        //  cout<<board[i]<<" ";
        // cout<<endl; 
        bool vis[31]={false};
        queue<pair<int,int>> q;
        q.push({1,0});
        while(!q.empty())
         {
             pair<int,int> p=q.front();
             int u=p.first;
             vis[u]=true;
             int dist=p.second;
             if(u==30)
              break;
             q.pop(); 
             for(int v=u+1;v<=u+6 && v<31;v++)
              {
                  if(!vis[v])
                   {
                       pair<int,int> p;
                       p.first=v;
                       p.second=dist+1;
                       if(board[v]!=-1)
                        p.first=board[v];
                       q.push(p);    
                   }
              }
         }
        return q.front().second; 
    }
};