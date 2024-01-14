class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        int range=0;
        string res;
        int n=s.length();
        
        for(int i=n-1;i>=0;i--){
            if(s[i]=='-')continue;
            
            res.push_back(toupper(s[i]));
            range++;
            
            if(range%k==0){
                res.push_back('-');
                range=0;
            }
        }
        
        if(res.back()=='-')res.pop_back();
        
       reverse(res.begin(),res.end()); 
        
        return res;
        
        
        
        
    }
};