class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.length();
        
        int left=0,right=0;
        
        int minLen=INT_MAX;
        string res="";
        int onesCount=0;
        
        while(right<n){
            
            if(s[right]=='1')onesCount+=1;
            
            while(onesCount==k){
                
                auto windowSize= right-left+1;
                if(windowSize<minLen){
                    
                    minLen= windowSize;
                    res= s.substr(left,windowSize);
                }
                else if(windowSize== minLen){
                    
                    auto str= s.substr(left,windowSize);
                    if(str<res)res= str;
                }
                
                if(s[left]=='1')onesCount-=1;
                
                left++;
            }
            
            right++;
        }
        
        return res;
    }
};