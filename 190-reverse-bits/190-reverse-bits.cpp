class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        vector<int>res(32,0);
        
       
     
       for(int i=0;i<32;i++){
           if(n & (1<<i))res[i]=1;
       }
        
      //  for(int i=0;i<32;i++)cout<<res[i];
        
      //  cout<<endl;
        
        uint32_t ans=0;
        
        int j=0;
        for(int i=31;i>=0;i--){
            ans=ans + pow(2,j)*res[i];
            j++;
        }
        
        return ans;
        
    }
};