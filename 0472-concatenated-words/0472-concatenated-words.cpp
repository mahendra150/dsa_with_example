class Solution {
public:
    unordered_map<string,bool> h;
    bool dfs(string &word,set<string> &st){
        if(h.count(word)){
            return h[word];
        }
        
        for(int i=0;i<word.length();i++){
            
            auto prefix= word.substr(0,i+1);
            auto suffix= word.substr(i+1);
            
            if( ( st.count(prefix) and st.count(suffix) ) or ( st.count(prefix) and dfs(suffix,st) ) ){
                
                return h[word]= true;
            }
        }
               
               return h[word]= false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        int n= words.size();
        
        set<string> st(words.begin(),words.end());
        
        vector<string> res;
        for(auto word: words){
            
            auto canBeConstructed= dfs(word,st);
            
            if(canBeConstructed)res.push_back(word);
        }
        
        return res;
        
    }
};