#include<bits/stdc++.h>

using namespace std;

stack<char> stac; 
string tmp="";

void order(char s)       // this function is for operators other than brackets 
{                      //here if the inserted operator if less or equal in value than the that in top of stack then it will be removed and appended to the string 
   map<char,int> mp;    
   mp['^']=3;
   mp['*']=2;
   mp['/']=2;
   mp['-']=1;
   mp['+']=1; 
   while(!stac.empty())
    {
       if(mp[s]<=mp[stac.top()])
        {
         tmp+=stac.top();
         stac.pop();
        }
       else
        {
          break;
        }
    }
   stac.push(s);    
}

void traverse(char s)   // this is for brackets if you get a closing bracket then all operators within the bracket is appended
{
  char temp;    
  vector<pair<char,char>> v;
  v.push_back(make_pair('(',')'));
  v.push_back(make_pair('{','}'));
  v.push_back(make_pair('[',']')); 
  for(int i=0;i<v.size();i++)
   {
       if(s==v[i].second)
        {
         temp=v[i].first;
         break;
        }
   }
  while(!stac.empty())
  {
    if(stac.top()!=temp)
    {
     tmp+=stac.top();
     stac.pop(); 
    }
    else
     {
        stac.pop(); 
        break;
     }
  }
}

string infixToPostfix(string s)
{
    // Your code here
    char pre[]={'+','-','*','/','^','{','}','(',')','[',']'};
    int i,j,c=0;
    for(i=0;i<s.length();i++)
    {
        c=0;
        for(j=0;j<11;j++)
         {
            if(s[i]!=pre[j])
             continue;
            c=1; 
            break;
         }
        if(c==0)
         {
            tmp+=s[i]; 
         }
        else
         {
            if(stac.empty() || s[i]=='(' || s[i]=='{' || s[i]=='[')
             stac.push(s[i]);
            else
             {
                if(s[i]==')' || s[i]=='}' ||s[i]==']')  
                 traverse(s[i]);
                else
                 order(s[i]);
             }
         }
    }
  while(!stac.empty())
   {
       tmp+=stac.top();
       stac.pop();
   }
  //cout<<stac.size()<<endl; 
  string temp=tmp;
  tmp="";
  return temp;    
}


int main()
{
    int t;
    cin>>t;
    //int M[MAX][MAX];
    while(t--)
    {
      //tmp="";    
      string str;
      cin>>str;
      cout<<infixToPostfix(str)<<endl;
    }
}