/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int start=1,end=n;
        
        while(start<=end){
            int mid=end + (start-end)/2;
            
            int res=guess(mid);
            if(res==0)return mid;
            else if(res>0)start=mid+1;
            else if(res<0)end=mid-1;
        }
        
        return start;
        
    }
};