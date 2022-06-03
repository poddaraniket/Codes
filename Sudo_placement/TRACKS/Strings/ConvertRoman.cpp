#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	 {
	 	int n;
	 	cin>>n;
	 	convertRoman(n);
	 }
}

void ConvertRoman(int n)
{
//Your code here
 //string str="";
 int i=12;
 int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
 string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
 while(n>0)
 {
     int d=n/num[i];
     n%=num[i];
     while(d--)
     {
         cout<<sym[i];
     }
    i--; 
 }
}