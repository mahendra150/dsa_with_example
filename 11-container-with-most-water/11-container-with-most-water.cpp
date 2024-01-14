class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int n=height.size();
        
        int left=0,right=n-1;
        int max_area=INT_MIN;
        
        while(left<right){
            if(height[left]<height[right]){
                max_area=max(max_area,height[left]*(right-left));
                left++;
            }
            else{
                max_area=max(max_area,height[right]*(right-left));
                right--;
            }
            
        }
        
        return max_area;
    }
};