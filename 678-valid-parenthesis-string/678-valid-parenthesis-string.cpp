class Solution {
public:
    bool checkValidString(string s) {
        int n=s.length();
        
        int openMin=0;
        int openMax=0;
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                openMin++;
                openMax++;
            }
            else if(s[i]==')'){
                openMin--;
                openMax--;
            }
            else if(s[i]=='*'){
                openMax++;
                openMin--;
            }
            if(openMin<0)openMin=0;
            if(openMax<0)return false;
        }
        
        return openMin==0;
        
    }
};