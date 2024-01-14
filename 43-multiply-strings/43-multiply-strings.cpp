class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" or num2=="0")return "0";
        int m=num1.length();
        int n=num2.length();
        vector<int>res(m+n,0);
        
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                int mul=(num1[i]-48)*(num2[j]-48);
                int remPos=(i+j+1);
                int carryPos=(i+j);
                mul+=res[remPos];
                
                int rem=mul%10;
                int carry=mul/10;
                
                res[remPos]=rem;
                res[carryPos]+=carry;
            }
        }
        
        string ans;
        
        //for trailing zeroes
        int i=0;
        while(res[i]==0)i++;
        
        while(i<res.size()){
            ans+=to_string(res[i]);
            i++;
        }
        
        return ans;
        
    }
};