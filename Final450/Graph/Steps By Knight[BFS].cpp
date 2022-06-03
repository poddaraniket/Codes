//O(N^2)

int dir[8][2]={{-1,-2},{-2,-1},{1,2},{2,1},{-1,2},{2,-1},{1,-2},{-2,1}};
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    vector<vector<int>> board(N+1,vector<int> (N+1,INT_MAX));
	    if(KnightPos[0]==TargetPos[0] && KnightPos[1]==TargetPos[1])
	        return 0;
	    board[KnightPos[0]][KnightPos[1]]=0;
	    queue<pair<int,int>> q;
	    q.push({KnightPos[0],KnightPos[1]});
	    while(!q.empty()){
	        int r=q.front().first;
	        int c=q.front().second;
	        q.pop();
	        for(int i=0;i<8;i++){
	            int x=dir[i][0]+r;
	            int y=dir[i][1]+c;
	            if(x>=1 && x<=N && y>=1 && y<=N)
	            {
	                if(board[r][c]+1<board[x][y])
	                {
	                    board[x][y]=board[r][c]+1;
	                    q.push({x,y});
	                }
	            }
	        }
	    }
	    return board[TargetPos[0]][TargetPos[1]];
	}