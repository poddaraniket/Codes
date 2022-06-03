// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


// User function template for C++
 bool vis[50][50];

void reset()
{
    memset(vis,false,sizeof(vis));
}

bool isValid(int x,int y,int row,int col)
{
    if(x<0 || y<0 || x>=row || y>=col)
     return false;
    return true; 
}

bool dfs(vector<vector<char> >& board,int x,int y,string word)
{
    if(word.length()==1 && board[x][y]==word[0])
     return true;
    if(board[x][y]!=word[0])
     return false;
    vis[x][y]=true; 
    int x_dir[8] = {-1,-1,0,1,1,1,0,-1};
    int y_dir[8] = {0,1,1,1,0,-1,-1,-1};
    for(int i=0;i<8;i++)
     {
        int x1=x+x_dir[i];
        int y1=y+y_dir[i];
        if(isValid(x1,y1,board.size(),board[0].size()))
         {
            if(vis[x1][y1]==false)
             {
                if(dfs(board,x1,y1,word.substr(1)))
                 return true;
             }
         }
     }
    vis[x][y]=false;
    return false;
}

vector<string> boggle(vector<vector<char> >& board,
                      vector<string>& dictionary) {
    // Your code goes here
    int flag=0;
    vector<string> v;
    int row=board.size();
    int col=board[0].size();
    int size=dictionary.size();
    for(int k=0;k<size;k++)
     {
        reset(); 
        flag=0;
        string word=dictionary[k];
        for(int i=0;i<row;i++)
         {
            for(int j=0;j<col;j++)
             {
                if(board[i][j]==word[0])
                 {
                    if(dfs(board,i,j,word))
                     {
                         flag=1;
                         v.push_back(word);
                         break;
                     }
                 }
             }
            if(flag==1)
             break;
         }
     }
    return v; 
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<string> dictionary;
        for (int i = 0; i < n; ++i) {
            string s;
            cin >> s;
            dictionary.push_back(s);
        }
        
        int r, c;
        cin >> r >> c;
        vector<vector<char> > board(r);
        for (int i = 0; i < r; i++) {
            board[i].resize(c);
            for (int j = 0; j < c; j++) cin >> board[i][j];
        }
        vector<string> output = boggle(board, dictionary);
        if (output.size() == 0)
            cout << "-1";
        else {
            sort(output.begin(), output.end());
            for (int i = 0; i < output.size(); i++) cout << output[i] << " ";
        }
        cout << endl;
    }
}
  // } Driver Code Ends