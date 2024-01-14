class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int>freq;
        
        int n=s.length();
        int maxFreq=0;
        int l=0;
        int longest=(-1);
        for(int r=0;r<n;r++){
           freq[s[r]]++;
            maxFreq=max(maxFreq,freq[s[r]]);
            int windowLen=(r-l+1);
            int validWindow=windowLen-maxFreq;
            if(validWindow>k){
                freq[s[l]]--;
                l++;
            }
             longest=max(longest,r-l+1);
            
        }
        
        return longest;
        
        
    }
};