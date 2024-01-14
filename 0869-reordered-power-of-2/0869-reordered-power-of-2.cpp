class Solution {
public:
    string utility(int num){
        
        auto temp= to_string(num);
        sort(temp.begin(),temp.end());
        
        return temp;
    }
    bool reorderedPowerOf2(int n) {
        
        auto number= utility(n);
        
        
        for(int i=0;i<32;i++){
            
            if(number==utility(1<<i))return true;
        }
        
        return false;
    }
};