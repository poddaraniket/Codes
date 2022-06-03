//O(N+26^N) 
// insert + search
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

bool search(node *curr,string s,int index)
{
  //node *curr=root;
//  cout<<s[index]<<" ";
  for(int i=index;i<s.length();i++)
  {
      if(s[i]!='.'){
        int pt=s[i]-'a';
        if(curr->child[pt]==NULL)
         return false;
        curr=curr->child[pt];
      }
      else
       {
           for(int pt=0;pt<26;pt++)
            {
                
                if(curr->child[pt]!=NULL && search(curr->child[pt],s,i+1)){
                    return true;
                }
            }
            return false;
       }
  }
  return curr->ends;
}


int main()
{
    // input list of words
    insert("ad"); 
	insert("add"); 
	insert( "be"); 
	insert( "ben"); 
	insert( "beo"); 
	insert( "bet"); 
	
    
    
    cout<<search(root,"ad",0)<<endl;
    cout<<search(root,"add",0)<<endl;
    cout<<search(root,"ben",0)<<endl;
    cout<<search(root,"b.",0)<<endl;
    cout<<search(root,"b.t",0)<<endl;
    cout<<search(root,"b..",0)<<endl;
    cout<<search(root,"...",0)<<endl;
    cout<<search(root,"..o",0)<<endl;
    cout<<search(root,".",0)<<endl;
    cout<<search(root,".be",0)<<endl;
    cout<<search(root,"ab.",0)<<endl;
    return 0;
}