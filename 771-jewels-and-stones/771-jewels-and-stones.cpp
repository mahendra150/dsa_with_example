class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char,int>freq;
        
        for(int i=0;i<jewels.length();i++){
            char ch=jewels[i];
            freq[ch]++;
        }
        
        int res=0;
        for(int i=0;i<stones.length();i++){
            char ch=stones[i];
            if(freq.count(ch))res++;
        }
        
        return res;
        
    }
};