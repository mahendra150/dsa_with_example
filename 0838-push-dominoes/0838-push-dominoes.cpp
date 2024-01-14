class Solution {
public:
    string res;
    
    void add(int count,char ch){
        
        for(int i=0;i<count;i++){
            
            res.push_back(ch);
        }
    }
    string pushDominoes(string dominoes) {
        res="";
        
        int n= dominoes.length();
        
        auto left= dominoes[0];
        int indx=0;
        
        while(dominoes[indx] == '.' and indx<n){
            cout<<"hi"<<endl;
            indx++;
        }
        
        left= dominoes[indx];
        
        for(int i=0;i<indx;i++){
            
            if(left=='L')res.push_back(left);
            else res.push_back('.');
        }
        
        int count=0;
        
        for(int i=indx;i<n;i++){
            
            auto right= dominoes[i];
            
            if(right != '.'){
                
                if(left=='L' and right=='R'){        //Case : LR
                    
                    add(count,'.');
                }
                else if(left=='L' and right=='L'){   //Case : LL
                     
                    add(count,left);
                }
                else if(left=='R' and right=='R'){   //Case : RR
                    
                    add(count,right);
                }
                else{                                //Case : RL
                    
                    add(count/2,left);
                    if(count % 2 != 0)res.push_back('.');
                    add(count/2,right);
                }
                
                left=right;
                count=0;
                res.push_back(right);
            }
            else count+=1;
        }
        
       if(left=='R')add(count,'R');
        else add(count,'.');
        
        return res;
    }
};