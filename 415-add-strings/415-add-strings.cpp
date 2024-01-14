class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i=num1.length()-1;
        int j=num2.length()-1;
        int carry=0;
        string res="";
        
        while(i>=0 or j>=0 or carry){
            int sum=carry;
            
            if(i>=0)sum+=num1[i]-48;
            
            
            if(j>=0)sum+=num2[j]-48;
            
            int rem=sum%10;
            carry=sum/10;
            
           res=to_string(rem)+res;
            
            i--;
            j--;
        }
        
       if(carry==1)res=to_string(carry) + res;
        
        
        return res;
        
    }
};