#include<bits/stdc++.h>

using namespace std;


struct node{
    char c;
    int ends;
    string word;
    node *child[26];
};

struct node *getNode(char s)
{
    node *newNode =  new node;
    newNode->c=s;
    newNode->ends=0;
    newNode->word="";
    for(int i=0;i<26;i++)
     newNode->child[i]=NULL;
    return newNode; 
}

node *root=getNode('/');

void insert(string s){
    node *curr=root;
    for(int i=0;i<s.length();i++)
     {
         //cout<<s[i]<<endl;
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

bool search(string s)
{
  node *curr=root;
  for(int i=0;i<s.length();i++)
  {
      int index=s[i]-'a';
      if(curr->child[index]==NULL)
        return false;
      curr=curr->child[index];    
  }
  if(curr->ends>0)
  return true;
  return false; 
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
    
    
    cout<<search("hello")<<endl;
    cout<<search("hell")<<endl;
    cout<<search("helloi")<<endl;
    
    return 0;
}