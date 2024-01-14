class Solution {
public:
    string removeKdigits(string num, int k) {
        int n= num.length();
        if(k==n)return "0";
        
        stack<char>  s;
        
        for(int i=0;i<n;i++){
            
          while(!s.empty() and k and num[i]<s.top()){
              
              s.pop();
              k--;
          }
            s.push(num[i]);
        }
        
        //Edge case --> "1111"
        while(k){
            
            s.pop();
            k--;
        }
        
        string res="";
        
        while(!s.empty()){
            
            res+= s.top();
            s.pop();
        }
        
        while(res.length()>1 and res[res.length()-1]=='0')res.pop_back();
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};