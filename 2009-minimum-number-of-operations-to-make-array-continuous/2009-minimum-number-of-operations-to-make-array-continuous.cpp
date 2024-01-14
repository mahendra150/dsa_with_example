class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n= nums.size();
        
        set<int> st(nums.begin(),nums.end());
        vector<int> arr;
        while(!st.empty()){
            
            auto val= *(st.begin());
            st.erase(st.find(val));
            arr.push_back(val);
        }
        
        int validWindow=0;
        int left=0,right=0;
        
        
        while(right<arr.size()){
            
            while(arr[left]+n<=arr[right]){
                
                left++;
            }
            validWindow=max(validWindow,right-left+1);
            right++;
        }
        
        return (n-validWindow);
        
    }
};