class Solution {
public:
    long int utility(long int dividend,long int divisor){
        //base case
        if(dividend<divisor)return 0;
        //recursive case
        long int sum=divisor;
        long int quotient=1;
        
        while(sum+sum<=dividend){
            
            sum=sum+sum;
            quotient=quotient+quotient;
        }
        
        return quotient + utility(dividend-sum,divisor);
    }
    int divide(int dividend, int divisor) {
        
        bool neg=false;
        long int quotient=0;
        
        if((dividend<0 and divisor>0) or (dividend>0 and divisor<0) ) neg=true;
        
        
        long int ldividend=abs(dividend);
        long int ldivisor=abs(divisor);
        
        if(ldivisor==0 or (ldividend<ldivisor))return 0;
        
         quotient=  utility(ldividend,ldivisor);
        std::cout<<quotient<<endl;
        
        if(quotient>INT_MAX){
            if(neg){
                return INT_MIN;
            }
            else{
                return INT_MAX;
            }
        }
        
        if(neg)return -(quotient);
        
        return quotient;
        
        
        
    }
};