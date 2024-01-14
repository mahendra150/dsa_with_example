class Solution {
public:
    int  solve(string word){
        char ch=word[0];
        
        for(int i=1;i<word.length();i++){
            ch=min(ch,word[i]);
        }
        
        int count=0;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch)count++;
        }
        
        return count;
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int>v1,v2;
        
        for(int i=0;i<queries.size();i++){
            v1.push_back(solve(queries[i]));
        }
        
        for(int i=0;i<words.size();i++){
            v2.push_back(solve(words[i]));
        }
        
        sort(v2.begin(),v2.end());
        vector<int>res;
        
        for(int i=0;i<queries.size();i++){
            
            auto indx= upper_bound(v2.begin(),v2.end(),v1[i]) - v2.begin();
            auto subRes= v2.size()-indx;
            
            res.push_back(subRes);
        }
        
        return res;
    }
};