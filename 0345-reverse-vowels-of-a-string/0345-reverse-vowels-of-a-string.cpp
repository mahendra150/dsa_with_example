class Solution {
public:
    string reverseVowels(string s) {
        int n=s.length();
        unordered_map<char,bool>valid;
        
        valid['A']=true;
        valid['a']=true;
        valid['E']=true;
        valid['e']=true;
        valid['I']=true;
        valid['i']=true;
        valid['o']=true;
        valid['O']=true;
        valid['u']=true;
        valid['U']=true;
        
        int left=0;
        int right=n-1;
        
        while(left<right){
            
            while(left<right and !valid[s[left]])left++;
            
            while(left<right and !valid[s[right]])right--;
            
            swap(s[left],s[right]);
            
            left++;
            right--;
        }
        
        return s;
        
    }
};