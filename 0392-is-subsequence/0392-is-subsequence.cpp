class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int n= t.length();
        int m= s.length();
        
        vector<int>sFreq(26,0);
        vector<int> tFreq(26,0);
        for(int i=0;i<m;i++)sFreq[s[i]-97]+=1;
        
        int i=0,j=0;
        
        while(j<n){
            
            if(s[i]==t[j])i++;
            
            j++;
        }
        
        if(i==m)return true;
        
        return false;
        
    }
};