class Solution {
public:
    int squareSum(int num){
        int res=0;
        while(num){
            int rem=num%10;
            res+=(rem*rem);
            num/=10;
        }
        return res;
    }
    bool isHappy(int n) {
        int s=n,f=n;
            do{
            s=squareSum(s);
            f=squareSum(f);
            f=squareSum(f);
            if(f==1)return true;
        }while(s != f);
            
            
        return false;
    }
};