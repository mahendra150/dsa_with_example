class Solution {
public:
    bool checkRecord(string s) {
        int n=s.length();
        
        int a=0,l=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='A')a++;
            if(s[i]=='L')l++;
            else l=0;
            if(a>=2 or l>=3)return false;
        }
        
        return true;
    }
};