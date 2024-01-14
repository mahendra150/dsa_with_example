class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int res=0;
        
        for(int i=0;i<columnTitle.length();i++){
            char ch=columnTitle[i];
            
            res*=26;
            res+= (ch-65)+1;
        }
        
        return res;
    }
};