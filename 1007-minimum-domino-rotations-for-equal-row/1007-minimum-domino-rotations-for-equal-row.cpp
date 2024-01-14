class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size();
        
        vector<int>a(n);
        vector<int>b(n);
        a=tops;
        b=bottoms;
        
        vector<int>countA(7,0);
        vector<int>countB(7,0);
        vector<int>countSame(7,0);
        
        for(int i=0;i<n;i++){
            int num1=a[i];
            int num2=b[i];
            
            countA[num1]++;
            countB[num2]++;
            
            if(num1==num2)countSame[num1]++;
        }
        
        int minSwap=INT_MAX;
        
        for(int number=1;number<=6;number++){
            if(countA[number]+countB[number]-countSame[number]==n){
                //case of chosen number
                int option1=countA[number];
                int option2=countB[number];
                
                int possibleAns=min(option1,option2)-countSame[number];
                
                minSwap=min(minSwap,possibleAns);
            }
        }
        
        
        return (minSwap==INT_MAX)?(-1):minSwap;
        
    }
};