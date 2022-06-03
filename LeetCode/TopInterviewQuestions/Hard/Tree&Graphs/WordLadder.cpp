class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int beginIndex=-1,endIndex=-1;
        unordered_set<string> word;
        for(int i=0;i<wordList.size();i++){
            word.insert(wordList[i]);
            if(beginWord==wordList[i])
                beginIndex=i;
            if(endWord==wordList[i])
                endIndex=i;
        }
        if(endIndex==-1)
            return 0;
        if(beginIndex!=-1)
            word.erase(beginWord);
        queue<string> q;
        q.push(beginWord);
        int depth=0;
        //O(N)
        while(!q.empty()){
            depth++;
            int size=q.size();
            while(size--){
                string curr=q.front();
                q.pop();
                if(curr.length()!=endWord.length())
                    continue;
                for(int i=0;i<curr.length();i++){   //O(N)
                    string temp=curr;
                    //replace every chracter and check
                    for(char c='a';c<='z';c++){   //O(26)
                        temp[i]=c;
                        //does it match with already chosen string
                        if(temp==curr)
                            continue;
                        // does it match with the desired string
                        if(temp==endWord)
                            return depth+1;
                        // does it match with any string
                        if(word.find(temp)!=word.end()){    //O(logN)
                           q.push(temp);
                           word.erase(temp); 
                        }
                    }
                }
            }
        }
        return 0;
    }
};