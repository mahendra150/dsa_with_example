class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n= prices.size();
        
        vector<int> nums= prices;
        stack<int> st;
        vector<int> res(n,0);
        
        // for(int i=0;i<n;i++)res[i]= prices[i];
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() and nums[i]<=nums[st.top()]){
                
                res[st.top()]= nums[i];
                st.pop();
            }
            
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            
            prices[i]-= res[i];
        }
        
        return prices;
        
    }
};