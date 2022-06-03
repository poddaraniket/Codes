#include<iostream>
using namespace std;
 
// Size of given matrix is M X N
#define M 6
#define N 6

int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void replaceSurroundedUtil(char mat[M][N],int x,int y){
  //  cout<<"*"<<endl;
    mat[x][y]='1';
    //cout<<mat[x][y]<<endl;
    for(int i=0;i<4;i++)
     {
        int r=dir[i][0]+x;
        int c=dir[i][1]+y;
        if(r>=0 && c>=0 && r<M && c<N && mat[r][c]=='O')
         {
            replaceSurroundedUtil(mat,r,c); 
         }
     }
}

void replaceSurrounded(char mat[M][N])
{
    for(int i=0;i<M;i++)
     {
        if(mat[i][0]=='O') 
          replaceSurroundedUtil(mat,i,0); 
     }
    for(int i=0;i<M;i++)
     {
        if(mat[i][N-1]=='O') 
          replaceSurroundedUtil(mat,i,N-1); 
     }
    for(int j=0;j<N;j++)
     {
        if(mat[0][j]=='O') 
          replaceSurroundedUtil(mat,0,j); 
     }
    for(int j=0;j<N;j++)
     {
        if(mat[N-1][j]=='O') 
          replaceSurroundedUtil(mat,N-1,j); 
     }
    for(int i=0;i<M;i++)
     {
         for(int j=0;j<N;j++)
          {
            if(mat[i][j]=='O')
             mat[i][j]='X';
            if(mat[i][j]=='1')
             mat[i][j]='O';
          }
     }
    cout<<"_____________"<<endl; 
}

int main()
{
    char mat[][N] =  {{'X', 'O', 'X', 'O', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
    replaceSurrounded(mat);
 
 
    for (int i=0; i<M; i++)
    {
      for (int j=0; j<N; j++)
          cout << mat[i][j] << " ";
      cout << endl;
    }
    return 0;
}