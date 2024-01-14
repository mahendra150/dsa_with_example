class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        
        int carry=0;
        string res="";
        
        while(i>=0 or j>=0 or carry){
            int sum=carry;
            if(i>=0){
                sum+=a[i]-48;
            }
            if(j>=0){
                sum+=b[j]-48;
            }
            
            int rem=sum%2;
            res=to_string(rem)+res;
            
            carry=sum/2;
            
            i--;
            j--;
            
            }
        
        if(carry==1)res=to_string(carry)+res;
        
        return res;
        
    }
};