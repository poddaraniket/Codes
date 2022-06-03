//Prerequiste -> getSubsequence
// It saves space O(n) 
// max total characters in stack at once (n+1)*n
// Similar question (Print keypad,print stairs,print maze,print maze with jumps)
// Teaches you how you can print instead of using list to store the data

/*

c=ques[0];
rst=ques.substr(1);
      
(take the character)rst|ans+c  rst|ans (did not take the character)
                      \        /
                       ques|ans

            c=c     .|abc .|ab .|ac .|a .|bc .|b .|c .|. 
            rst=.      \   /     \   /   \   /    \   /
                        c|ab      c|a     c|b      c|. 
            c=b           \      /         \       /
            rst=c          \    /           \     /
                            bc|a             bc|.       
                              \              /
            c=a                \            /
            rst=bc              \          /
                                    abc|.

*/
#include <iostream>
using namespace std;

void printSS(string ques, string ans){
    // write your code here
    if(ques.length()==0){
        cout<<ans<<endl;
        return;
    }
    char c=ques[0];
    string rst=ques.substr(1);
    printSS(rst,ans+ques[0]);
    printSS(rst,ans);
}

int main(){
    string str;
    cin >> str;
    printSS(str, "");
}