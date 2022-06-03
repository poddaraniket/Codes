class Solution {
public:
    
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]!='.'){
                    int box=(i/3)*3 + (j/3);
                    string row="ROW"+to_string(i)+board[i][j];
                    string col="COL"+to_string(j)+board[i][j];
                    string sm="BOX"+to_string(box)+board[i][j];
                    if(s.find(row)!=s.end() || s.find(col)!=s.end() || s.find(sm)!=s.end())
                        return false;
                    s.insert(row);
                    s.insert(col);
                    s.insert(sm);
                }
            }
        }
        return true;
    }
};