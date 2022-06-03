class Solution {
public:
    vector<string> cellsInRange(string s) {
        char startCol=s[0];
        char startRow=s[1];
        char endCol=s[3];
        char endRow=s[4];
        vector<string> ans;
        string temp;
        for(char i=startCol;i<=endCol;i++){
            temp.push_back(i);
            for(char j=startRow;j<=endRow;j++){
                temp.push_back(j);
                ans.push_back(temp);
                temp.pop_back();
            }
            temp.pop_back();
        }
        return ans;
    }
};