class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int greater=INT_MAX;
        int smaller=INT_MIN;
        for(int i=0;i<n-2;i++){
            int left=i+1;
            int right=n-1;
            while(left<right){
            int sum=nums[i]+nums[left]+nums[right];
            if(sum==target)return sum;
            else if(sum>target){
                greater=min(greater,sum);
                right--;
            }
            else if(sum<target){
                smaller=max(smaller,sum);
                left++;
            }
        }
            
    }
        
        if(greater!=INT_MAX and smaller!=INT_MIN){
            int diff1=abs(target-smaller);
            int diff2=abs(target-greater);
            
            if(diff2<diff1)return greater;
            else return smaller;
        }
        if(greater!=INT_MAX and smaller==INT_MIN)return greater;
        
        return smaller;
        
        
        
        
        
    }
};