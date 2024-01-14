class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n=nums.size();
        int left=0,right=n-1;
        vector<int>fin;
        int indx=n-1;
        while(left<=right)
        {
            int ans1=nums[left]*nums[left];
            int ans2=nums[right]*nums[right];
            if(ans2>ans1)
            {fin.push_back(ans2);
             right--;
            }
            else 
            {
                fin.push_back(ans1);
                left++;
            }
        }
       reverse(fin.begin(),fin.end());
        return fin;
        
    }
};