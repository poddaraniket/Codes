

 int dir[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

    bool isSafe(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m)
         return false;
        return true; 
    }

    bool dfs(vector<vector<char> >& board,int x,int y,string word)
    {
        if(word.length()==0)
         return true;
        char temp=board[x][y]; 
        board[x][y]='$';
        for(int k=0;k<8;k++){
            int x1=x+dir[k][0];
            int y1=y+dir[k][1];
            if(isSafe(x1,y1,board.size(),board[0].size()) && board[x1][y1]==word[0])
             {
                return dfs(board,x1,y1,word.substr(1)); 
             }
        }
        return false;
    }

	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	    vector<pair<int,int>> v[27];
	    for(int i=0;i<board.size();i++)
	     {
	         for(int j=0;j<board[i].size();j++)
	          {
	              v[board[i][j]-'a'].push_back({i,j});
	          }
	     }
	   // for(int i=0;i<26;i++)
	   //  {
	   //      for(int j=0;j<v[i].size();j++)
	   //       cout<<v[i][j].first<<" "<<v[i][j].second<<",";
	   //      cout<<endl; 
	   //  }
	    vector<string> ans; 
	   // for(int i=0;i<dictionary.size();i++)
	   //  {
	   //      string word=dictionary[i];
	   //      int loc=word[0]-'a';
	   //      for(int j=0;j<v[loc].size();j++)
	   //       {
	   //           int x=v[loc][j].first;
	   //           int y=v[loc][j].second;
	   //           cout<<"*"<<endl;
	   //           if(dfs(board,x,y,word.substr(1))){
	   //              ans.push_back(word);
	   //              break;
	   //           }
	   //       }
	   //  }
	    return ans; 
	}