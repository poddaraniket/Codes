//O(n^2)

#include <bits/stdc++.h>
using namespace std;

#define MAX_ROW 10
#define MAX_COL 10

void maxAreaRectWithSumZero(int mat[MAX_ROW][MAX_COL],int row,int col)
{
    int zero[row][col];
    int one[row][col];
    memset(zero,0,sizeof(zero));
    memset(one,0,sizeof(one));
    if(mat[0][0]==0)
     zero[0][0]=1;
    else
     one[0][0]=1;
    for(int i=1;i<col;i++)
     {
      if(mat[0][i]==0){
        zero[0][i]=zero[0][i-1]+1;
        one[0][i]=one[0][i-1];
      }
      else{
        one[0][i]=one[0][i-1]+1;
        zero[0][i]=zero[0][i-1];
      }
     }
    for(int i=1;i<row;i++)
     {
      if(mat[i][0]==0){
        zero[i][0]=zero[i-1][0]+1;
        one[i][0]=one[i-1][0];
      }
      else{
        one[i][0]=one[i-1][0]+1;
        zero[i][0]=zero[i-1][0];
      }
     }
    for(int i=1;i<row;i++)
     {
         for(int j=1;j<col;j++)
          {
            if(mat[i][j]==0)
            {
                zero[i][j]=zero[i-1][j]+zero[i][j-1]-zero[i-1][j-1]+1;
                one[i][j]=one[i-1][j]+one[i][j-1]-one[i-1][j-1];
             }
            else
            {
                zero[i][j]=zero[i-1][j]+zero[i][j-1]-zero[i-1][j-1];
                one[i][j]=one[i-1][j]+one[i][j-1]-one[i-1][j-1]+1;
            }  
          }
     }
    int maxi=0; 
    for(int i=0;i<row;i++)
     {
         for(int j=0;j<col;j++)
          {
            if(zero[i][j]==one[i][j])
              maxi=max(maxi,zero[i][j]*2);
          }
     }
    cout<<maxi<<endl; 
    
}

int main()
{
    int mat[MAX_ROW][MAX_COL] = { {0, 0, 1, 1},
                                    {0, 1, 1, 0},
                                    {1, 1, 1, 0},
                                  {1, 0, 0, 1} };    
    int row = 4, col = 4;
    maxAreaRectWithSumZero(mat, row, col);
    return 0;                      
                        
} 