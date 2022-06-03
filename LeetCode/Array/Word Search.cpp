class Solution {
    bool vis[201][201];
public:
    
    bool check(vector<pair<int,int>> v[],string word,int x,int y)
    {
        //cout<<word[0]<<endl;
        if(word.length()==0)
            return true;
        vis[x][y]=true;
        for(int i=0;i<v[word[0]].size();i++)
        {
            int x1=v[word[0]][i].first;
            int y1=v[word[0]][i].second;
            //cout<<x1<<" "<<y1<<endl;
            if(abs(x1-x)+abs(y1-y)<=1 && vis[x1][y1]==false)
            {
                //vis[x1][y1]=true;
                if(check(v,word.substr(1,word.length()),x1,y1))
                {
                   return true;   
                }
            }
        }
       vis[x][y]=false; 
       return false; 
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        memset(vis,false,sizeof(vis));
        vector<pair<int,int>> v[256];
        for(int i=0;i<board.size();i++)
         {
            for(int j=0;j<board[0].size();j++)
            {
                v[board[i][j]].push_back({i,j});
            }
         }
       // cout<<"*"<<endl;
        for(int i=0;i<v[word[0]].size();i++)
        {
            int x=v[word[0]][i].first;
            int y=v[word[0]][i].second;
          //  cout<<x<<" "<<y<<endl;
            //vis[x][y]=true;
            if(vis[x][y]==false && check(v,word.substr(1,word.length()),x,y))
               return true; 
        }
        return false;
    }
};