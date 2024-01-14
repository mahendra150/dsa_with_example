class Solution {
public:
    bool isPowerOfTwo(int n) {
        
         int number=n;
        if(number<=0)return false;
        
        if(((number) & (number-1))==0)return true;
        
        return false;
    }
};