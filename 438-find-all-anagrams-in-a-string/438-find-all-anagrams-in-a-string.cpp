class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int sLen=s.length();
        int window=p.length();
        
        if(sLen<window)return {};
        
        vector<int>pFreq(26,0);
        vector<int>sFreq(26,0);
        vector<int>ans;
        
        for(int i=0;i<window;i++){
            pFreq[p[i]-97]++;
            sFreq[s[i]-97]++;
        }
        if(pFreq==sFreq)ans.push_back(0);
        
        
        for(int i=window;i<sLen;i++){
            sFreq[s[i-window]-97]--;
            sFreq[s[i]-97]++;
            if(sFreq==pFreq)ans.push_back(i-window+1);
        }
        
        return ans;
        
        
        
    }
};