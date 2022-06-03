 #include <bits/stdc++.h>
using namespace std;

struct contact
{
    string field1; 
    int field2;
};

void buildgraph(contact arr[],int n,vector<vector<int>> &mat){
    for(int i=0;i<n;i++)
     {
         for(int j=i+1;j<n;j++)
          {
            if(arr[i].field1==arr[j].field1 || arr[i].field2==arr[j].field2)
             {
                mat[i][j]=1;
                mat[j][i]=1;
                break;
             }
          }
     }
}

void findConnected(int src,vector<bool> &vis,vector<vector<int>> &mat,vector<pair<string,int>> &sol,contact arr[],int n)
{
    vis[src]=true;
    sol.push_back({arr[src].field1,arr[src].field2});
    for(int i=0;i<n;i++)
     {
        if(mat[src][i] && !vis[i]) 
          findConnected(i,vis,mat,sol,arr,n);
     }
}

void findSameContacts(contact arr[],int n)
{
    vector<vector<pair<string,int>>> sol;
    vector<vector<int>> mat(n,vector<int>(n,0));
    vector<bool> vis(n,false);
    buildgraph(arr,n,mat);
    for(int i=0;i<n;i++)
     {
        vector<pair<string,int>> v; 
        if(!vis[i]){
          findConnected(i,vis,mat,v,arr,n);  
          sol.push_back(v);
        }
     }
    for(int i=0;i<sol.size();i++)
     {
        for(int j=0;j<sol[i].size();j++)
         {
            pair<string,int> p=sol[i][j];
            cout<<"{"<<p.first<<","<<p.second<<"},";
         }
        cout<<endl; 
     }
}

int main()
{
    contact arr[] = {
        {"abc" ,9987},
        {"xyz",9986},
        {"dfg",9987}
    };
 
    int n = sizeof arr / sizeof arr[0];
    findSameContacts(arr, n);
    return 0;
}