#include <bits/stdc++.h>
using namespace std;

#define N 4

int matrix[][N]={{5,6,7,10},{6,8,15,18},{7,9,16,20},{9,12,19,24}};
bool vis[N][N];


bool dfs(int key,int i,int j)
{
   if(i>=N || j>=N || key<matrix[i][j] || vis[i][j]==true) 
    return false;
   cout<<matrix[i][j]<<endl;      
   vis[i][j]=true;    
   if(key==matrix[i][j])
    return true;
   if(dfs(key,i+1,j) || dfs(key,i,j+1) || dfs(key,i+1,j+1))
    return true;
   return false;    
}

int main() {
	// your code goes here
	int key;
	cin>>key;
	cout<<dfs(key,0,0)<<endl;
	memset(vis,false,sizeof(vis));
	return 0;
}
