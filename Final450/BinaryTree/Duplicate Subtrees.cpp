string printAllDupsUtil(Node* root,vector<Node*> &v,map<string,int> &mp){
    if(root==NULL)
     return "$"; // so that if any side is NULL we can identify that by $
    string s="";
    s+=printAllDupsUtil(root->left,v,mp);
    s+=to_string(root->data);
    s+=printAllDupsUtil(root->right,v,mp);
    // Check from bottom up  
    if(mp[s]==1)
    {
       v.push_back(root);    
    }
    mp[s]++;
     //cout<<root->data<<endl;
    return s; 
    
}

vector<Node*> printAllDups(Node* root)
{
    // Code here
    vector<Node*> v;
    map<string,int> mp;
    printAllDupsUtil(root,v,mp);
    return v;
}