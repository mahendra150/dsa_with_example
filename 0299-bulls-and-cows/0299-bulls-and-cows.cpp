class Solution {
public:
    string getHint(string secret, string guess) {
        int n=secret.length();
        int m=guess.length();
        
        //secret freq map
        vector<int>sFreq(10,0);
        //guess freq map
        vector<int>pFreq(10,0);
        
        int bulls=0,cows=0;
        
        for(int i=0;i<n;i++){
           auto  ch=secret[i]-48;
            sFreq[ch]++;
        }
        
        for(int j=0;j<m;j++){
            auto ch=guess[j]-48;
            pFreq[ch]++;
        }
        
        for(int i=0,j=0;i<n and j<m;i++,j++){
            if(secret[i]==guess[j]){
                auto ch=secret[i]-48;
                bulls++;
                sFreq[ch]--;
                pFreq[ch]--;
            }
        }
        
        for(int i=0,j=0;i<10 and j<10;i++,j++){
            if(sFreq[i]!=0 and pFreq[i]!=0){
                if(pFreq[i]==sFreq[i]){
                    cows+=pFreq[i];
                }
                else if(pFreq[i]>sFreq[i]){
                    cows+=sFreq[i];
                }
                else if(sFreq[i]>pFreq[i]){
                    cows+=pFreq[i];
                }
            }
        }
            
        string res="";
        res+=to_string(bulls);
        res+='A';
        res+=to_string(cows);
        res+='B';
            
        return res;
        
    }
};