class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        //   aaabbb c     
        
        int n=fruits.size();
        int currLen=0,maxLen=INT_MIN;
        int a=(-1) ,b=(-1);
        int b_count=0;
        
        for(int i=0;i<n;i++){
            int c=fruits[i];
            if(c != a and c != b){
                a=b;
                b=c;
                currLen=b_count+1;
                b_count=1;
            }
            else if(c==b){
                currLen+=1;
                b_count+=1;
            }
            else if(c==a){
                currLen+=1;
                a=b;
                b=c;
                b_count=1;
            }
            
            maxLen=max(maxLen,currLen);
        }
        
        return maxLen;
        
    }
};