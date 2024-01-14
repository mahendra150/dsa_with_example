class Solution {
public:
    int countDigitOne(int n) {
        
        if(n<=0)return 0;
        if(n <= 9)return 1;
        
        //DP Computation
        
        unordered_map<int,int> mp;
        mp[9]= 1;
        
        for(int i=9; i<(INT_MAX-9)/10; i=10*i+9){
            
            mp[10*i+9]= 10*mp[i] + (i+1);
        }
        
        //Breaking the Bigger Problem into Smaller Problems
        
        //Finding Nearest (tens) or (hundreds) or (thousands)
        int temp= n;
        int divisor= 1;
        
        while(temp/10){
            temp/=10;
            divisor*=10;
        }
        
        int rem= n%divisor;
        int first_digit= n/divisor;
        
        int ans=0;
        
        //The Main Breaking Step + Edge Cases
        ans+= first_digit*mp[divisor-1];          // f(3467)= 3*f(999);
        ans+=(first_digit>1)? divisor:0;
        ans+=(first_digit==1)? rem+1:0;
        
        //For Remaining Numbers
        ans+=countDigitOne(rem);
        
        return ans;
        
        
    }
};