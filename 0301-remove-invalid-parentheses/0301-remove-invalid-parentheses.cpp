class Solution {
public:
    vector<string> res;
    unordered_map<string,bool> h;
    
    void dfs(string s,int minInvalid){
        if(h[s]==true)return;
        
        h[s]= true;
        int n= s.length();
        //base case
        
        if(minInvalid==0){
            
            // Valid String
            if(!getMinInvalid(s)){
                
                res.push_back(s);
            }
        }
        //recursive case
        
        for(int i=0;i<n;i++){
            
            auto left= s.substr(0,i);
            auto right= s.substr(i+1);
            
            dfs(left+right,minInvalid-1);
        }
    }
    int getMinInvalid(string &s){
        // Helper Function
        int n= s.length();
        stack<char> st;
        
        for(int i=0;i<n;i++){
            
            if(s[i]=='('){
                
                st.push(s[i]);
            }
            
            else if(s[i]==')'){
                
                if(!st.empty() and st.top()=='(')st.pop();
                else st.push(s[i]);
            }
        }
        
        return st.size();
    }
    vector<string> removeInvalidParentheses(string s) {
        
        int minInvalid= getMinInvalid(s);
        
        dfs(s,minInvalid);
        
        return res;
    }
};