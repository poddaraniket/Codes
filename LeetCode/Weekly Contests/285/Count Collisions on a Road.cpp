//O(N)
class Solution {
public:
    int countCollisions(string directions) {
        int collisions=0;
        string s;
        for(int i=0;i<directions.length();i++){
            // cout<<collisions<<" "<<s<<endl;
            char currDir=directions[i];
            s.push_back(currDir);
            while(s.size()>=2){
                char dir2=s.back();
                s.pop_back();
                char dir1=s.back();
                s.pop_back();
                if(dir1=='S' && dir2=='L'){
                    collisions++;
                    s.push_back('S');
                }
                else if(dir1=='R' && dir2=='S'){
                    collisions++;
                    s.push_back('S');
                }
                else if(dir1=='R' && dir2=='L'){
                    // cout<<"()"<<endl;
                    collisions+=2;
                    s.push_back('S');
                }
                else{
                    s.push_back(dir1);
                    s.push_back(dir2);
                    break;
                }
                
            }
        }
       return collisions; 
    }
};