class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,window;
        
        for(auto i:t)need[i]++;
        
        int right=0,left=0,valid=0;
        int minLen=INT_MAX;
        int start=(-1);
        
        while(right<s.length()){
            auto ch=s[right];
            window[ch]++;
            if(need.count(ch)){
                if(need[ch]==window[ch])valid++;
            }
            while(valid==need.size()){
                int windowLen=(right-left+1);
                if(windowLen<minLen){
                    start=left;
                    minLen=windowLen;
                }
                window[s[left]]--;
                if(need.count(s[left])){
                    if(window[s[left]] < need[s[left]])valid--;
                }
                left++;
            }
            right++;
        }
        
        return minLen==INT_MAX?"":s.substr(start,minLen);
        
        
        
    }
};