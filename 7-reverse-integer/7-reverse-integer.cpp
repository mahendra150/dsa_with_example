class Solution {
public:
    int reverse(int x) {
        
        int rev=0;
        int lowerLimit=(-pow(2,31))/10;;
        int upperLimit=(pow(2,31)-1)/10;
        
        while(x){
            int rem=x%10;
           if(rev>=lowerLimit and rev<=upperLimit){
               rev= rev*10 + rem;
               x/=10;
           }
            else return 0;
            
        }
        
        return rev;
        
    }
};