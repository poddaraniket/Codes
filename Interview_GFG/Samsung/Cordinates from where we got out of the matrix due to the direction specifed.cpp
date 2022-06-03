// O()

bool isSafe(int i,int j,int N,int M)
     {
         if(i<0 || j<0 || i>=N || j>=M)
          return false;
         return true; 
     }
    
    pair<int,int> endPoints(vector<vector<int>> matrix){
        //code here
        int N=matrix.size();
        int M=matrix[0].size();
        unordered_map<char,pair<int,int>> dirMp;
        dirMp['U']={-1,0};
        dirMp['R']={0,1};
        dirMp['D']={1,0};
        dirMp['L']={0,-1};
        unordered_map<char,char> mp;
        mp['U']='R';
        mp['R']='D';
        mp['D']='L';
        mp['L']='U';
        pair<int,int> p(0,0);
        char dir='R';
        while(1)
         {
             int i=p.first;
             int j=p.second;
             if(matrix[i][j]==1)
              {
                dir=mp[dir];
                matrix[i][j]=0;
              }
             pair<int,int> d=dirMp[dir]; 
             if(!isSafe(i+d.first,j+d.second,N,M))
              break;
             p.first=i+d.first;
             p.second=j+d.second;
         }
        return p; 
    }