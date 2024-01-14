class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n= tokens.size();
        
        sort(tokens.begin(),tokens.end());
        int score= 0;
        
        int left=0,right=n-1;
        int res=0;
        
        while(left<=right){
            
            if(power>=tokens[left]){
                
                power-= tokens[left];
                score+=1;
                res=max(res,score);
                left++;
            }
            else if(score){
                
                score-=1;
                power+= tokens[right];
                right--;
            }
            else break;
        }
        
        return res;
        
        
    }
};