class Solution {
public:
    vector<int> utility(string &word){
        
        vector<int>freq(26,0);
        
        for(int i=0;i<word.length();i++){
            
            freq[word[i]-97]+=1;
        }
        
        return freq;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        
        vector<int> need(26,0);
        vector<int> temp(26,0);
        for(auto word:words2){
            
            temp= utility(word);
            for(int i=0;i<26;i++){
                
                need[i]=max(need[i],temp[i]);
            }
        }
        
        vector<string> res;
        for(auto word:words1){
            
            temp= utility(word);
            int i;
            for(i=0;i<26;i++){
                
                if(temp[i]<need[i])break;
            }
            if(i==26)res.push_back(word);
        }
        
        return res;
        
    }
};