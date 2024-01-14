class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window=s1.length();
        int sLen=s2.length();
        
        if(sLen<window)return false;
        
        vector<int>pFreq(26,0);
        vector<int>sFreq(26,0);
        
        for(int i=0;i<window;i++){
            pFreq[s1[i]-97]++;
            sFreq[s2[i]-97]++;
        }
        if(sFreq==pFreq)return true;
        
        for(int i=window;i<sLen;i++){
            sFreq[s2[i-window]-97]--;
            sFreq[s2[i]-97]++;
            if(sFreq==pFreq)return true;
        }
        return false;
    
    }
};