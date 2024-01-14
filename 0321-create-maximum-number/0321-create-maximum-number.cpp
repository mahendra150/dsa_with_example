class Solution {
public:
    bool isGreater(vector<int> &nums1,int p1,vector<int> &nums2,int p2){
        // Custom Comparator --> utility for Merging
        
        for(;p1<nums1.size() and p2<nums2.size();p1++,p2++){
            
            if(nums1[p1]>nums2[p2])return true;
            
            if(nums2[p2]>nums1[p1])return false;
        }
        
        // For a case--> (9453) and (945)
        
        return p1 != nums1.size();
        
    }
    vector<int> formLargestNumber(vector<int> &nums,int k){
        //Monotonic Stack 
        
        int remain= k;
        stack<int> s;
        
        for(int i=0;i<nums.size();i++){
            
            while(!s.empty() and nums[i]>s.top() and nums.size()-1-i>=remain){
                
                s.pop();
                remain++;
            }
            
            if(remain>0){
                
                s.push(nums[i]);
                remain--;
            }
        }
        
        vector<int> subRes;
        
        while(!s.empty()){
            
            subRes.push_back(s.top());
            s.pop();
        }
        
        reverse(subRes.begin(),subRes.end());
        return subRes;
        
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();
        int m= nums2.size();
        
        vector<int> res(k);
        for(int ki=max(0,k-m);ki<=min(n,k);ki++){
            
            vector<int> tempRes(k);
            
           vector<int> res1= formLargestNumber(nums1,ki);
           vector<int> res2= formLargestNumber(nums2,k-ki);
            
            int i=0,j=0,len=0;
            while(i<res1.size() or  j<res2.size()){
                
                tempRes[len++]=isGreater(res1,i,res2,j)?res1[i++]:res2[j++];
            }
            
            if(!isGreater(res,0,tempRes,0)){
                
                res= tempRes;
            }
        }
        
        return res;
        
    }
};