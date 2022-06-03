// O(nm*nm)
struct node{
        char c;
        int ends;
        node *child[26];
        string word;
    };
    
    struct node *getNode(char s){
        node* newNode=new node;
        newNode->c=s;
        newNode->ends=0;
        newNode->word="";
        for(int i=0;i<26;i++)
         newNode->child[i]=NULL;
        return newNode; 
    }
    
    node *root=getNode('/');
    
    //Trie insert
    void insert(string s){
        node *curr=root;
        int i=0,index;
        while(s[i]){
            index=s[i]-'a';
            if(curr->child[index]==NULL)
             {
                 curr->child[index]=getNode(s[i]);
             }
            curr=curr->child[index];
            i++;
        }
        curr->ends+=1;
        curr->word=s;
    }
    
public:

    int dir[8][2]={{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}};

    bool isSafe(int x,int y,int n,int m){
        if(x<0 || y<0 || x>=n || y>=m)
         return false;
        return true; 
    }

    void solve(vector<vector<char> >& board,int x,int y,vector<string> &ans,node *curr)
    {
        int index=board[x][y]-'a';
        if(board[x][y]=='$' || curr->child[index]==NULL) 
          return;
        curr=curr->child[index];
        if(curr->ends>0)
         {
             ans.push_back(curr->word);
             curr->ends-=1;
         }
        char temp=board[x][y];
        board[x][y]='$';
        
        for(int k=0;k<8;k++)
         {
             int x1=x+dir[k][0];
             int y1=y+dir[k][1];
             if(isSafe(x1,y1,board.size(),board[0].size()))
              {
                  solve(board,x1,y1,ans,curr);
              }
         }
        board[x][y]=temp; 
    }
    
	vector<string> wordBoggle(vector<vector<char> >& board, vector<string>& dictionary) {
	    // Code here
	   for(int i=0;i<dictionary.size();i++)
	    {
	        insert(dictionary[i]);
	    }
	   vector<string> ans;
	   for(int i=0;i<board.size();i++)
	    {
	        for(int j=0;j<board[0].size();j++)
	        {
	            solve(board,i,j,ans,root);
	        }
	    }
	   return ans; 
	}