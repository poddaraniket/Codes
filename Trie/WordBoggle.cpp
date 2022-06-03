//O(4*N^2)

class Solution {
public:
    
    struct node{
       char c;
       int end;
       string word;
       node *child[26]; 
    };
    
    struct node* getNode(char s){
        node* newNode=new node;
        newNode->c=s;
        newNode->end=0;
        newNode->word="";
        for(int i=0;i<26;i++){
            newNode->child[i]=NULL;
        }
        return newNode;
    }
    
    node* root=getNode('/');
                        
    void insert(string s){
        node* curr=root;
        for(int i=0;i<s.length();i++){
            int index=s[i]-'a';
            if(curr->child[index]==NULL){
                curr->child[index]=getNode(s[i]);
            }
            curr=curr->child[index];
        }
        curr->end+=1;
        curr->word=s;
    }                    
    
    int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
    
    bool isSafe(int x,int y,int m,int n){
        if(x<0 || y<0 || x>=m || y>=n)
            return false;
        return true;
    }
    
    void solve(vector<vector<char>>& board,vector<string> &ans,node *curr,int x,int y){
        int index=board[x][y]-'a';
        // cout<<board[x][y]<<endl;
        if(board[x][y]=='$' || curr->child[index]==NULL)
            return;
        curr=curr->child[index];
        // cout<<curr->word<<endl;
        if(curr->end>0){
            // cout<<"*"<<endl;
            ans.push_back(curr->word);
            curr->end-=1;
        }
        char ch=board[x][y];
        board[x][y]='$';
        for(int k=0;k<4;k++){
            int i=x+dir[k][0];
            int j=y+dir[k][1];
            if(isSafe(i,j,board.size(),board[0].size())){
                solve(board,ans,curr,i,j);
            }
        }
        board[x][y]=ch;
    }
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            insert(words[i]);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                solve(board,ans,root,i,j);
            }
        }
        return ans;
    }
};