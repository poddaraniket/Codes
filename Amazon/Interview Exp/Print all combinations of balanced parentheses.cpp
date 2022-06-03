#include <iostream>
#define MAX_SIZE 100
  
using namespace std;

void printParenthesis(int n,int countOpen,int countClose,string s)
{
    //cout<<s<<" "<<countOpen<<endl;
    if(countClose==n)
     {
        cout<<s<<" ";
        return;
     }
    if(countOpen<n) 
      printParenthesis(n,countOpen+1,countClose,s+'{');
    if(countOpen>countClose)
     printParenthesis(n,countOpen,countClose+1,s+'}');
}

int main()
{
    int n = 2;
      
    printParenthesis(n,0,0,"");
  
    return 0;
}