class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,bool>h;
        
       for(auto i:nums1)h[i];
        
        for(auto i:nums1)h[i]=true;
        
        vector<int>res;
        
        for(auto i:nums2){
            if(h[i])res.push_back(i);
            h[i]=false;
        }
        
        return res;
        
    }
};