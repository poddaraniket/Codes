#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int,int> a,pair<int,int> b)
 {
    if(a.second==b.second)
     return a.first<b.first;
    return a.second<b.second; 
 }

vector<int> solution(vector<vector<int>> matrix)
{
    vector<int> v;
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
            v.push_back(matrix[i][j]);
        }
    }
    sort(v.begin(),v.end());
    vector<pair<int,int>> r;
    r.push_back({v[0],1});
    int cnt=0;
    for(int i=1;i<v.size();i++){
        if(v[i]==v[i-1])
         r[cnt].second++;
        else
         {
            r.push_back({v[i],1});
            cnt++;
         }
    }
    sort(r.begin(),r.end(),cmp);
    int t=0;
    for(int i=0;i<r.size();i++)
     {
        int counter=r[i].second;
        while(counter--){
            v[t++]=r[i].first;
        }
     }
    return v;
}

int main() {
	// your code goes here
	int m;
	cin>>m;
	vector<vector<int>> matrix;
	for(int i=0;i<m;i++)
	{
	    vector<int> v; 
	    for(int j=0;j<m;j++)
	     {
	        int a;
	        cin>>a;
	        v.push_back(a);
	     }
	    matrix.push_back(v);
	}
	vector<int> sorted=solution(matrix);
// 	for(int i=0;i<sorted.size();i++){
// 	    cout<<sorted[i]<<" ";
// 	}
// 	cout<<endl;
	int n=sorted.size();
	int total=(2*m-2);
	int i=0;
	// Lower half[Row Fix] start from m-1
	for(int k=total;k>=total/2;k--)
	{
        int ROW=m-1;
       for(int col=k-ROW;col<=m-1;col++) {
           cout<<ROW<<" "<<col<<endl;
           matrix[ROW--][col]=sorted[i++];
       }
    }
    // UPPER HALF[Col Fixed] start from 0
    for(int k=(total/2)-1;k>=0;k--){
        int COL=0;
        for(int row=k-COL;row>=0;row--)
         {
            cout<<row<<" "<<COL<<endl; 
            matrix[row][COL++]=sorted[i++]; 
         }
    }
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[0].size();j++)
        {
         cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
	return 0;
}
