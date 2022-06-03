string dupSubUtil(Node *root,unordered_map<string,int> &mp)
{
    if(root==NULL)
     return "$";
    string s=""; 
    // if(root->left!=NULL && root->right!=NULL)
    //  {
    //     s=to_string(root->data);
    //     return s;
    //  }
    s+=dupSubUtil(root->left,mp);
    s+=to_string(root->data);
    s+=dupSubUtil(root->right,mp);
    mp[s]++;
    return s;
}

bool dupSub(Node *root)
{
     //your code here
     unordered_map<string,int> mp;
     dupSubUtil(root,mp);
    //  for(auto x:mp)
    //   cout<<x.first<<" "<<x.second<<endl;
     for(auto it=mp.begin();it!=mp.end();it++)
      {
          string s=it->first;
          if(it->second>=2 && s.length()>3)
           return true;
      }
    return false;  
}