#include <bits/stdc++.h>
using namespace std;

int x[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
int y[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

bool vis[50][50];

bool dfs(char *grid,string s,int row,int col,int r,int c){
    // char temp=s[0];
    // *(grid+r*col+c)='*';
    if(*(grid+r*col+c)!=s[0])
     {
        return false; 
     }
    
     int len=s.length();
    for(int i=0;i<8;i++)
     {
        int k; 
        int x1=r+x[i];
        int y1=c+y[i];
        for(k=1;k<len;k++){
           if(x1<0 || y1<0 || x1>=row || y1>=col)
             break;
           if(*(grid+x1*col+y1)!=s[k])
            {
                break; 
            }
           x1+=x[i];
           y1+=y[i];
        }
       if(k==len)
        return true;
     }
    // //vis[r][c]=false;
    // *(grid+r*col+c)=temp;
    return false; 
}

void patternSearch(char *grid,string s,int r,int c){
    // vector<vector<bool>> vis(r,vector<bool>(c,false));
    memset(vis,false,sizeof(vis));
    // for(int i=0;i<r;i++)
    //  {
    //     for(int j=0;j<c;j++)  
    //      {
    //         cout<<vis[i][j]<<" "; 
    //      }
    //     cout<<endl; 
    //  }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++)
         {
            if(dfs(grid,s,r,c,i,j))
             cout << "pattern found at "<< i << ", "<< j << endl;
         }
    }
}

int main()
{
     int R = 3, C = 13;
    char grid[R][C] = { "GEEKSFORGEEKS",
                        "GEEKSQUIZGEEK",
                        "IDEQAPRACTICE" };
 
    patternSearch((char *)grid, "GEEKS", R, C);
    cout <<"-------------" <<endl;
    
    patternSearch((char *)grid, "EEE", R, C);
    return 0;
}