class Solution {
public:
    int myAtoi(string s) {
        int n=s.length();
        // int lowerLimit= (-pow(2,31))/10;
        // int upperLimit= (pow(2,31)-1)/10;
        
        int i=0;
        while(i<n and s[i]==' '){
            i++;
        }
        
        
        s=s.substr(i);
        i=0;
        int sign=(+1);
        if(s[0]=='-'){
            sign= (-1);
            i=1;
        }
        if(s[0]=='+')i=1;
        
        long long int res=0;
        for(;i<s.length();i++){
            if(s[i]==' ' or !isdigit(s[i]))break;
            
            int x= s[i]-48;
            res= res*10 + x;
            if(sign==(-1) and -1*res<INT_MIN)return INT_MIN;
            if(sign==(+1) and 1*res>INT_MAX)return INT_MAX;
        }
        
        return (int) sign*res;
        
    }
};