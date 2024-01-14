class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.length();
        
        unordered_map<char,bool>visited;
        unordered_map<char,int>freq;
        
        for(char i='a';i<='z';i++){
            visited[i]=false;
        }
        for(auto i:s){
            freq[i]++;
        }
        
        stack<char>st;
        
        for(auto ch:s){
            
            freq[ch]--;
            if(visited[ch])continue;
            
            while(!st.empty() and ch<st.top() and freq[st.top()]){
                visited[st.top()]=false;
                st.pop();
            }
            st.push(ch);
            visited[ch]=true;
        }
        
        string res="";
        while(!st.empty()){
            res=st.top()+res;
            st.pop();
        }
        
        
        return res;
        
    }
};