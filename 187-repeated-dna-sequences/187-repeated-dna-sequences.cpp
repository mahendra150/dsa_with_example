class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.length();
        
        unordered_map<string,int>freq;
        string currSequence="";
        
        for(int i=0;i<10;i++){
            currSequence+=s[i];
        }
        freq[currSequence]++;
        
        for(int i=10;i<n;i++){
            currSequence.erase(currSequence.begin());
            currSequence+=s[i];
            freq[currSequence]++;
        }
        
        vector<string>ans;
        for(auto str:freq){
            if(str.second>=2)ans.push_back(str.first);
        }
        
        return ans;
        
    }
};