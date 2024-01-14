class Solution {
public:
    int calculate(string s) {
        
        char prev='+';
        s+='+';
        stack<int>st;
        
        long long number=0;
        
        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                number=number*10+(s[i]-48);
            }
            else if(s[i]=='+' or s[i]=='-' or s[i]=='*' or s[i]=='/'){
                if(prev=='+'){
                    st.push(number);
                    number=0;
                }
                else if(prev=='-'){
                    st.push(number*(-1));
                    number=0;
                }
                else if(prev=='*'){
                    int ele=st.top();
                    st.pop();
                    ele=ele*number;
                    st.push(ele);
                    number=0;
                }
                else if(prev=='/'){
                    int ele=st.top();
                    st.pop();
                    ele=ele/number;
                    st.push(ele);
                    number=0;
                }
                prev=s[i];
            }
        }
        
        long long ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        
        return ans;
        
    }
};