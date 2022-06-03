#include <bits/stdc++.h>
using namespace std;

void conv(string a,string b)
{
  long long int cal=0,j;
  cal=(a[0]-64); 
  for(j=1;j<a.size();j++)
    {
      cal*=26;
      cal+=(a[j]-64);  
    }
  cout<<"R"<<stoi(b)<<"C"<<cal<<endl;
}

int main() {
 long long int n,i,cal=0,f=0,c=0,len,len1,j,temp;
 string sent,stri="",num1="",num2="",demo;
 vector<string> s;
 cin>>n;
 for(i=0;i<n;i++)
  {
    cin>>sent;
    s.push_back(sent);
  } 
 for(i=0;i<n;i++)
  {
    stri="";
    num1="";
    num2="";
    c=0;
    f=0;
    //cout<<"*"<<endl;
    demo=s[i];
    //len=demo.size();
    if(demo[0]=='R')
     {
       for(j=0;j<demo.size();j++)
        {
          //cout<<"/"<<endl;
          if(demo[j]>=48 && demo[j]<=57)
          {
            f=1;
            if(c==0)
             num1+=demo[j];
            else
             num2+=demo[j]; 
            //f=1;
          }
           else
            {
              if(f==1)
               {
                  c=1;
                  continue;
               }
              stri+=demo[j]; 
            }
        }
       if(c==1)
         {
           stri="";
           //cout<<num1<<" "<<num2<<endl;
            len1=stoi(num2);
          //  if(len1%26!=0)
          //  { 
           //cout<<len1<<endl; 
            while(len1>26)
             {
               temp=len1%26;
               //cout<<temp<<endl;
               if(temp!=0)
               {
                 stri=(char)(temp+64)+stri;
                 len1-=temp;
               }
               else
               {
                 stri='Z'+stri;
                 len1-=26;
                 //len1--;
               }
                len1/=26;
             }
            stri=(char)(len1+64)+stri;
            cout<<stri<<stoi(num1)<<endl; 
           
         }
       else
         conv(stri,num1);    
     }
    else
      {
        //cout<<"/"<<endl;
        for(j=0;j<demo.size();j++)
         {
           //cout<<"/"<<endl;
           if(demo[j]>=48 && demo[j]<=57)
             num1+=demo[j];
           else
             stri+=demo[j];
         }
        //cout<<stri<<" "<<num1<<endl; 
        conv(stri,num1);   
      }
  } 
}