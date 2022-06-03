#include <bits/stdc++.h>
using namespace std;

bool solution(vector<int> arr,vector<vector<int>> req){
    unordered_map<int,int> mp;
    for(int i=0;i<req.size();i++)
     {
        mp[req[i][0]]=i; 
     }
    int i=0; 
    while(i<arr.size()) {
        int index=mp[arr[i]];
        vector<int> v=req[index];
        for(int j=0;j<v.size();j++)
         {
            int val=arr[i++]; 
            if(val!=v[j])
             return false;
         }
    }
    return i<arr.size()?false:true;
}

int main() {
	// your code goes here
	vector<int> arr{1,5,4,3,2,8};
	vector<vector<int>> req{{1,5,5},{3,2},{8}};
	cout<<solution(arr,req)<<endl;
	return 0;
}
