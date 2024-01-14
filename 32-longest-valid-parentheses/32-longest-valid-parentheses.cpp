class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length();
        
        stack<char>characterStack;
        stack<int>indexStack;
        int maxLen=0;
        
        indexStack.push(-1);
        
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                characterStack.push('(');
                indexStack.push(i);
            }
            else if(s[i]==')'){
                if(!characterStack.empty() and characterStack.top()=='('){
                    characterStack.pop();
                    indexStack.pop();
                    int problemIndex=indexStack.top();
                    maxLen=max(maxLen,i-problemIndex);
                }
                else{
                    indexStack.push(i);
                }
            }
        }
        
        return maxLen;
        
    }
};