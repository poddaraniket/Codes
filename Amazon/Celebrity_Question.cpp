#include <iostream>
using namespace std;



int main() {
    int N=4;
	int MATRIX[N][N] = {{0, 0, 1, 0}, 
                    {0, 0, 1, 0}, 
                    {0, 0, 0, 0}, 
                    {0, 0, 1, 0}}; 
    
    int l=0,r=N-1,f=0;
    while(l<r)
     {
        //l knows r
        if(MATRIX[l][r]==1)
         l++;
        else
         r--;
     }
    for(int i=0;i<N;i++)
     {
        if(i!=l && MATRIX[i][l]==0 && MATRIX[l][i]==1)
         {
             f=1;
             break;
         }
     }
    if(f==1)
     cout<<"NO Celebrity"<<endl;
    else
     cout<<"Celebrity is "<<l+1<<endl;
	return 0;
}
