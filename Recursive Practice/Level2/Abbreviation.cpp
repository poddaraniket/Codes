//TC-> O(2^n) using recursive tree

// SC-> O(|str|)

/*


when we go left we accept the curr index string and add to our ans, but before 
that we also add the count(no. of characters we ignored), if its >0, the we make 
the count as 0. 

when we go right we ignore the curr index character and increase our count by 1

                                 
 (pep)          (pe1) (p1p)      (p2)  (1ep)        (1e1) (2p)      (3)
 pep|0          pe|1  p1p|0       p|2  1ep|0        1e|1  2p|0      .|3
      \          /       \         /      \          /     \         /
       \        /         \       /        \        /       \       /
        pep|pe|0           pep|p|1          pep|1e|0         pep|.|2    
                 \            /                \           /
                  \          /                  \         /
                     pep|p|0                     pep|.|1 
                            \                   /
                             \                 /
                                   pep|.|0   
*/


#include<bits/stdc++.h>

using namespace std;

void solution(string str, string asf,int count, int pos){
    //write your code here
    if(pos==str.length()){
        if(count>0){
            asf+=to_string(count);
        }
        cout<<asf<<endl;
        return;
    }
    string number=count>0 ? to_string(count) : "";   
    // taking the pos char
    solution(str,asf+number+str[pos],0,pos+1);
    // not taking the pos char
    solution(str,asf,count+1,pos+1);
}


int main(){
    string str;
    cin>>str;
    solution(str,"",0,0);
    return 0;
}