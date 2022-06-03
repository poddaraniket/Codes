#include <bits/stdc++.h>
using namespace std;

string one[] = { "", "one ", "two ", "three ", "four ", 
                 "five ", "six ", "seven ", "eight ", 
                 "nine ", "ten ", "eleven ", "twelve ", 
                 "thirteen ", "fourteen ", "fifteen ", 
                 "sixteen ", "seventeen ", "eighteen ", 
                 "nineteen " }; 
  
string ten[] = { "", "", "twenty ", "thirty ", "forty ", 
                 "fifty ", "sixty ", "seventy ", "eighty ", 
                 "ninety " }; 

string num(int n,string p)
{
    string s="";
    if(n>19)
     {
        s+=ten[n/10]+one[n%10]; 
     }
    else
     {
        s+=one[n]; 
     }
    if(n)
     s+=p;
    return s; 
}

void ConvertToWords(long long int n)
{
    string ans="";
    ans+=num(n/10000000,"crore ");
    ans+=num((n/100000)%100,"lakhs ");
    ans+=num((n/1000)%100,"thousand ");
    ans+=num((n/100)%10,"hundred ");
    if(n>100 && n%100!=0)
     ans+="and ";
    ans+=num(n%100,""); 
    cout<<ans<<endl; 
}

int main() {
	// your code goes here
	long long int  n;
	cin>>n;
	ConvertToWords(n);
	
	return 0;
}
