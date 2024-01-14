class Solution {
public:
    bool isValid(int number){
        bool check=false;
        
        while(number){
            int carry=number%10;
            if(carry==2 or carry==5 or carry==6 or carry==9)check=true;
            else if(carry==3 or carry==4 or carry==7)return false;
            
            number/=10;
        }
        
        return check;
    }
    int rotatedDigits(int n) {
        vector<int>dp(n+1,0);
        
        for(int number=2;number<=n;number++){
            
            if(isValid(number)){
                dp[number]++;
            }
            
            dp[number]+=dp[number-1];
        }
        
        return dp[n];
        
    }
};