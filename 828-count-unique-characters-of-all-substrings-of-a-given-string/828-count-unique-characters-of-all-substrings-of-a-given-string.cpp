class Solution {
public:
    int uniqueLetterString(string s) {
        int n=s.length();
        int index[26][2];
        memset(index,(-1),sizeof(index));
        int res=0;
        
        for(int i=0;i<n;i++){
            int c=s[i]-65;
            res+=(i-index[c][1])*(index[c][1]-index[c][0]);
            index[c][0]=index[c][1];
            index[c][1]=i;
        }
        
        int i=n;
        for(int c=0;c<26;c++){
            res+=(i-index[c][1])*(index[c][1]-index[c][0]);
        }
        
        return res;
        
    }
};