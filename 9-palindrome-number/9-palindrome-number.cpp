class Solution {
public:
    bool utility(string &input){
        int n=input.length();
        
        int i=0,j=n-1;
        
        while(i<j){
            if(input[i]!=input[j])return false;
            i++;
            j--;
        }
        
        return true;
    }
    bool isPalindrome(int x) {
        if(x<0)return false;
        
        string input=to_string(x);
        return utility(input);
        
    }
};