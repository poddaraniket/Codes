//O(N)
class Solution {
public:
    
    bool findPath(TreeNode* root, int value,string &path){
        if(root==NULL)
            return false;
        if(root->val==value){
            return true;
        }
        bool leftChild=findPath(root->left,value,path);
        if(leftChild){
            path.push_back('L');
            return true;
        }
        bool rightChild=findPath(root->right,value,path);
        if(rightChild){
            path.push_back('R');
            return true;
        }
        return false;
    }
    
    string getDirections(TreeNode* root, int startValue, int destValue) {
        string startPath,destPath;
        findPath(root,startValue,startPath);
        findPath(root,destValue,destPath);
        reverse(startPath.begin(),startPath.end());
        reverse(destPath.begin(),destPath.end());
        cout<<startPath<<" "<<destPath<<endl;
        int s=startPath.length();
        int d=destPath.length();
        int i;
        for(i=0;i<min(s,d);i++){
            if(startPath[i]!=destPath[i])
                break;
        }
        string path=destPath.substr(i);
        for(int j=i;j<s;j++){
            path='U'+path;
        }
        return path;
    }
};