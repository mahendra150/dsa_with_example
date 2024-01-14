class Solution {
public:
    int slidingWindow(string s,int k,int numOfUniqueTarget){
        int n=s.length();
        
        int left=0;
        int right=0;
        int maxLen=0;
        unordered_map<char,int> freq;
        int numOfUnique=0;
        int valid=0;
        
        while(right<n){
            
            if(freq[s[right]]==0)numOfUnique+=1;
            freq[s[right]]+=1;
            if(freq[s[right]]==k)valid++;
            
            while(numOfUnique>numOfUniqueTarget){
                
                if(freq[s[left]]==k)valid--;
                freq[s[left]]-=1;
                
                if(freq[s[left]]==0)numOfUnique-=1;
                left++;
            }
            
            if(valid==numOfUnique){
                maxLen=max(maxLen,right-left+1);
            }
            right++;
            
        }
        
        return maxLen;
    }
    int longestSubstring(string s, int k) {
        
        int res=0;
        
        for(int T=1;T<=26;T++){
            
            res=max(res,slidingWindow(s,k,T));
        }
        
        return res;
    }
};