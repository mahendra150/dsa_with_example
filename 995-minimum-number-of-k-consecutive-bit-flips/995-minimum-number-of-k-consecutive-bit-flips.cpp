class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size();
        int flipTimes=0;
        vector<int>isFlipped(n,0);
        int res=0;
        
        for(int i=0;i<n;i++){
            if(i>=k)flipTimes-=isFlipped[i-k];
            if(!nums[i] and flipTimes%2!=0)continue;
            else if(nums[i] and flipTimes%2==0)continue;
            else if(!nums[i] and flipTimes%2==0){
                if(i+k>n)return -1;
                res++;
                flipTimes++;
                isFlipped[i]=1;
            }
            else if(nums[i] and flipTimes%2!=0){
                if(i+k>n)return -1;
                res++;
                flipTimes++;
                isFlipped[i]=1;            
            }
            
        }
        return res;
    }
};