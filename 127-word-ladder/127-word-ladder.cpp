class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        set<string>s(wordList.begin(),wordList.end());
        
        if(!s.count(endWord))return 0;
        
        queue<string>q;
        q.push(beginWord);
        
        int ladder=0;
        
        while(!q.empty()){
            ladder++;
            int n=q.size();
            while(n--){
                auto word=q.front();
                q.pop();
                for(int i=0;i<word.length();i++){
                    char c=word[i];
                    for(char j='a';j<='z';j++){
                        if(c != j){
                            word[i]=j;
                            if(s.count(word)){
                                if(word==endWord)return ladder+1;
                                q.push(word);
                                auto address=s.find(word);
                                if(address != s.end())s.erase(word);
                            }
                        }
                    }
                    word[i]=c;
                }
            }
        }
        
        return 0;
        
        
        
    }
};