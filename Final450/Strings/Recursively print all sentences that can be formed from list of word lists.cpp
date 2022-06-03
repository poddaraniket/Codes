#include <bits/stdc++.h>
using namespace std;

#define R 3
#define C 3

void print(string arr[R][C],int r,string output)
{
    if(R==r)
    {
        cout<<output<<endl;
        return;
    }
    for(int i=0;i<C;i++){
        if(arr[r][i]!="")
          print(arr,r+1,output+" "+arr[r][i]);
    }
}


int main() {
	 string arr[R][C]  = {{"you", "we"},
                        {"have", "are"},
                        {"sleep", "eat", "drink"}};
 
    print(arr,0,"");
 
	return 0;
}
