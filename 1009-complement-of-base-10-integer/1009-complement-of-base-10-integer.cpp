class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0)return 1;
        
        int num=n;
        
        int i=0;
        while(n){
            n/=2;
            i++;
        }
        
        int count=i;
        string res="";
        for(int i=0;i<count;i++){
            if(num & (1<<i))res= "0" + res;
            else res= "1" + res;
        }
        
        int pos=0;
        int ans=0;
        cout<<res<<endl;
        
        for(int i=res.length()-1;i>=0;i--){
            char x=res[i]; 
            // cout<<int(x)<<endl;
            ans+= (x-48)*pow(2,pos);
            pos++;
        }
        
        
        
        return ans;
        
    }
};