// Same as largest island/ food fill O(N^2)

#include<bits/stdc++.h>

using namespace std;

int maxi=0;

int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};

bool isSafe(int x,int y,int m,int n){
    if(x<0 || y<0 || x>=m || y>=n){
        return false;
    }
    return true;
}

void dfs(vector<vector<int>> &arr,int x,int y,int &sum){
    int m=arr.size();
    int n=arr[0].size();
    sum+=arr[x][y];
    arr[x][y]=0;
    for(int k=0;k<4;k++){
        int newX=x+dir[k][0];
        int newY=y+dir[k][1];
        if(isSafe(newX,newY,m,n) && arr[newX][newY]!=0){
            dfs(arr,newX,newY,sum);
        }
    }
}

void getMaxGold(vector<vector<int>> &arr){
    int m=arr.size();
    int n=arr[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            int sum=0;
            if(arr[i][j]!=0){
                dfs(arr,i,j,sum);
                maxi=max(maxi,sum);
            }
        }
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    vector<vector<int>> v(m,vector<int> (n));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
        }
    }
    getMaxGold(v);
    cout<<maxi<<endl;
    return 0;
}