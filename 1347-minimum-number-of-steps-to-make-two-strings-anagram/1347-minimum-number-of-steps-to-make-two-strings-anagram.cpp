class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> sFreq(26,0);
        vector<int> tFreq(26,0);
        
        for(int i=0;i<s.length();i++){
            
            sFreq[s[i]-97]+=1;
        }
        
        int steps=0;
        for(int i=0;i<t.length();i++){
            
            tFreq[t[i]-97]+=1;
        }
        
        for(int i=0;i<26;i++){
            
            if(tFreq[i] != sFreq[i]){
                if(sFreq[i]>tFreq[i])
                    steps+=(sFreq[i]-tFreq[i]);
            }
        }
        
        return steps;
        
    }
};