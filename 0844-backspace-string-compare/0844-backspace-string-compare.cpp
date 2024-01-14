class Solution {
public:
    string updated(string &temp){
        string res="";
        
        int i=0;
        int n=temp.length();
        
        while(i<n){
            
            if(temp[i] != '#'){
                res+=temp[i];
            }
            else{
                if(res.length()>0) res.pop_back();
            }
            i++;
        }
        
        return res;
    }
    bool backspaceCompare(string s, string t) {
        
        return updated(s)==updated(t);
    }
};