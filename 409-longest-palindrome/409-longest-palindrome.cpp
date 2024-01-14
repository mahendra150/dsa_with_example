class Solution {
public:
    int longestPalindrome(string s) {
       unordered_map<char,int>freq;
        int n=s.length();
        int result=0;
        
        for(int i=0;i<n;i++){
            freq[s[i]]++;
        }
        
        for(auto i:freq){
            result+=(i.second/2)*2;
            if(result%2==0 and i.second%2==1){
                result+=1;
            }
        }
        
        return result;
        
    }
};