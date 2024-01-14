class Solution {
public:
    int scoreOfParentheses(string s) {
        int n= s.length();
        
        int score=0;
        stack<int> scoreStack;
        
        for(int i=0;i<n;i++){
            
            auto ch= s[i];
            
            if(ch=='('){
                
                scoreStack.push(score);
                score=0;
            }
            else{
                
                auto val= scoreStack.top();
                
                score+= val + max(1,score);
                scoreStack.pop();
            }
        }
        
        return score;
    }
};