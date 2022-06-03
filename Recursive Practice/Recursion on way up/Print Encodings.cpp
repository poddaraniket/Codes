/*       
          .|1,2,3(abc)
                    \
                    3|1,2(ab)   .|1,23(bv) .|12,3(lc)  
                            \      /           \
                             23|1(b)            3|12(l)
                                    \          / 
                                     \        /
                                        123|.
*/




#include <iostream>
#include<string>
using namespace std;

void printEncoding(string str, string asf){
    // write your code here
    // cout<<asf<<endl;
    if(str.length()==0){
        cout<<asf<<endl;
        return;
    }
    if(str[0]=='0')
     return;
    char ch=(char)str[0]-'0'+96;
    // if(one=='0')
    if(ch>='a' && ch<='z'){
     printEncoding(str.substr(1),asf+ch);
    }
    if(str.length()>1){
        int val=stoi(str.substr(0,2));
        if(val<27){
            val+=96;
            printEncoding(str.substr(2),asf+(char)val);
        }
     }
}

int main(){
    string str;
    cin>>str;
    printEncoding(str,"");
    
}