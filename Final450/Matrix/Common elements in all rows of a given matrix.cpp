#include <bits/stdc++.h>
using namespace std;

#define M 4
#define N 5

void printCommonElements(int mat[M][N])
{
   unordered_map<int,int> mp;
   for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
         {
            if(mp[mat[i][j]]==i)
             mp[mat[i][j]]++;
         }
    }
    for(auto it=mp.begin();it!=mp.end();it++)
     {
        if(it->second==M)
         cout<<it->first<<" ";
     }
    cout<<endl; 
}


int main() {
int mat[M][N] =
    {
        {1, 2, 1, 4, 8},
        {3, 7, 8, 5, 1},
        {8, 7, 7, 3, 1},
        {8, 1, 2, 7, 9},
    };
 
    printCommonElements(mat);
	return 0;
}
