// Dynamic Approach

#include <bits/stdc++.h>
using namespace std;

#define INT_MAX 999999
#define V 4

void printDist(int dist[V][V])
{
    for(int i=0;i<V;i++)
     {
        for(int j=0;j<V;j++)
         {
             if(dist[i][j]==INT_MAX)
              cout<<"I"<<" ";
             else 
              cout<<dist[i][j]<<" ";
         }
        cout<<endl; 
     }
}

void flyodWarshall(int graph[V][V])
{
    int dist[V][V];
    for(int i=0;i<V;i++)
     {
        for(int j=0;j<V;j++)
         {
            dist[i][j]=graph[i][j]; 
         }
     }
    /*
    the concept id to find distance from every pair via an intermediate this will help us to get 
    min dist between pair of vertices eg (1,2) via 3,4 or 5 as intermediate this can get us shortest dist
    between 1,3 or 3,2 and so on....
    */
    for(int i=0;i<V;i++)
     {
        for(int u=0;u<V;u++)  
         {
            for(int v=0;v<V;v++)
             {
                if(u==i || v==i)
                 continue;
                if(dist[u][v]>dist[u][i]+dist[i][v])
                 dist[u][v]=dist[u][i]+dist[i][v];
             }
         }
     }
    printDist(dist); 
}


int main() {
	// your code goes here
	int graph[V][V] = { {0, 5, INT_MAX, 10},  
                        {INT_MAX, 0, 3, INT_MAX},  
                        {INT_MAX, INT_MAX, 0, 1},  
                        {INT_MAX, INT_MAX, INT_MAX, 0}  
                    };  
    flyodWarshall(graph);
	return 0;
}
