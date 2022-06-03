class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& formation) {
    int m=formation[0].size();
    int n=formation.size();
     for(int i=0;i<m;i++) // 0 1 2 3 4
     {
        int x=0,y=i;
        char cmp=formation[x][y];
        while(x<n && y<m)
         {
            if(formation[x][y]!=cmp)
             return false;
            x++;
            y++; 
         }
     }
    //COL
    for(int i=0;i<n;i++)
     {
        int x=i,y=0;
        char cmp=formation[x][y];
        while(x<n && y<m)
         {
            if(formation[x][y]!=cmp)
             return false;
            x++;
            y++; 
         }
     } 
    return true;  
    }
};