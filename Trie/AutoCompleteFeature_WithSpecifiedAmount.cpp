#include<bits/stdc++.h>

using namespace std;

struct node{
    char c;
    string word;
    int ends;
    node *child[26];
};

struct node *getNode(char s)
{
    node *newNode =  new node;
    newNode->c=s;
    newNode->word="";
    newNode->ends=0;
    for(int i=0;i<26;i++)
     newNode->child[i]=NULL;
    return newNode; 
}

node *root=getNode('/');

void insert(string s){
    node *curr=root;
    for(int i=0;i<s.length();i++)
     {
        int index=s[i]-'a';
        if(curr->child[index]==NULL)
         {
            curr->child[index]=getNode(s[i]);
         }
        curr=curr->child[index]; 
     }
    curr->ends+=1;
    curr->word=s;
}

void print(node *curr,int &top)
{
    if(top==0)
     return;
    if(curr->ends>0 && top>0)
     {
        cout<<curr->word<<endl;
        top--;
        curr->ends-=1;
        //return;
     }
    for(int i=0;i<26;i++)
     {
        if(curr->child[i]!=NULL)
         print(curr->child[i],top);
     }
}

int autoCorrect(string s,int top)
{
  node *curr=root;
  for(int i=0;i<s.length();i++)
   {
      int index=s[i]-'a';
      if(curr->child[index]==NULL)
        return 0;
      curr=curr->child[index];    
   }
  int count=top; 
  print(curr,count);
  if(count==top)
    return 0;
  else if(count>0)
   return -1;
  else 
   return 1;
}

int main()
{
    // input list of words
    insert("hello"); 
	insert("dog"); 
	insert( "hell"); 
	insert( "cat"); 
	insert( "a"); 
	insert( "hel"); 
	insert( "help"); 
	insert( "helps"); 
	insert( "helping");
    
    int val=autoCorrect("help",4);
    
    if(val==0)
     cout<<"No Word Present"<<endl;
    else if(val==-1)
     cout<<" No More Words Present"<<endl;
    else
     cout<<"Here are the required amount of words"<<endl;
    // autoCorrect("hell",1)
    // autoCorrect("h",3)
    
    return 0;
}