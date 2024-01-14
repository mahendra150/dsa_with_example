class Solution {
public:
    int calculate(string s) {
        int n= s.length();
        
        stack<int> st;
        
        int res=0;
        int sign= 1;
        
        // int lowerLimit=(-pow(2,31))/10;;
        // int upperLimit=(pow(2,31)-1)/10;
        
        for(int i=0;i<n;i++){
            
            if(isdigit(s[i])){
                
                int number=0;
                  number= number*10 + (s[i]-48);
                while(i+1<n and isdigit(s[i+1])){
                    
                  number= number*10 + (s[i+1]-48);
                    
                    i++;
                }
                
                res+= number*sign;
            }
            
            else if(s[i]=='+')sign= 1;
            
            else if(s[i]=='-')sign= (-1);
            
            else if(s[i]=='('){
                
                st.push(res);
                st.push(sign);
                res=0;
                sign= 1;
            }
            
            else if(s[i]==')'){
                
                auto pastSign= st.top();
                st.pop();
                auto pastRes= st.top();
                st.pop();
                
                res= res*pastSign + pastRes;
            }
        }
        
        return res;
    }
};