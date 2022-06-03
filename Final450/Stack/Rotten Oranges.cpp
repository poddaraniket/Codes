// O( R *C) 

int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
             {
                if(grid[i][j]==2)
                {
                  //cout<<i<<" "<<j<<endl;    
                  q.push({i,j});  
                }
                 
             }
        }
        int count=0;
        while(!q.empty())
         {
            int size=q.size();
           // cout<<size<<endl;
            //count++;
            while(size--)
            {
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                //[i-1,j], [i+1,j], [i,j-1], [i,j+1]
                if(i-1>=0 && grid[i-1][j]==1)
                 {
                   // cout<<i-1<<" "<<j<<endl; 
                    grid[i-1][j]=2;
                    q.push({i-1,j});
                 }
                if(i+1<grid.size() && grid[i+1][j]==1)
                 {
                     //cout<<i+1<<" "<<j<<endl;
                    grid[i+1][j]=2;
                    q.push({i+1,j});
                 }
                if(j-1>=0 && grid[i][j-1]==1)
                 {
                     //cout<<i<<" "<<j-1<<endl;
                    grid[i][j-1]=2;
                    q.push({i,j-1});
                 }
                if(j+1<grid[0].size() && grid[i][j+1]==1)
                 {
                     //cout<<i<<" "<<j+1<<endl;
                    grid[i][j+1]=2;
                    q.push({i,j+1});
                 }  
            }
            if(q.size()>0)
             count++;
         }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
             {
                if(grid[i][j]==1)
                {
                  return -1; 
                }
                 
             }
        }
        return count; 
    }