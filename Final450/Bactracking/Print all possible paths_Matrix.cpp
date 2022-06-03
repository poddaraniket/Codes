#include<bits/stdc++.h>

const int x=2;
const int y=3;


using namespace std;

void printAllPathsUtil(int mat[x][y],int m,int n,vector<vector<int>> &res,vector<int> &v,int r,int c){
    if(r==m-1 && c==n-1)
     {
        v.push_back(mat[r][c]);
        res.push_back(v);
        v.pop_back();
        return;
     }
    v.push_back(mat[r][c]);
    mat[r][c]*=-1; 
    if(r+1<m && mat[r+1][c]>0)
     printAllPathsUtil(mat,m,n,res,v,r+1,c);
    if(c+1<n && mat[r][c+1]>0)
     printAllPathsUtil(mat,m,n,res,v,r,c+1);
    v.pop_back(); 
    if(mat[r][c]<0)
     mat[r][c]*=-1;
}

void printAllPaths(int mat[x][y],int m,int n){
    vector<vector<int>> res;
    vector<int> v;
    printAllPathsUtil(mat,m,n,res,v,0,0);
    for(int i=0;i<res.size();i++)
     {
        for(int j=0;j<res[i].size();j++)
         cout<<res[i][j]<<" ";
        cout<<endl; 
     }
}

int main()
{
    int mat[2][3] = { {1, 2, 3}, {4, 5, 6} };
    printAllPaths(mat, 2, 3);
    return 0;
}