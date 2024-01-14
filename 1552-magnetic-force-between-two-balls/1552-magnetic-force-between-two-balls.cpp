class Solution {
public:
    bool isPossibleToPlace(vector<int>& position,int mid,int m)
    {
        int n=position.size();
        int placed=position[0];
        int count=1;
        for(int i=1;i<n;i++)
        {
            if(position[i]-placed>=mid)
            {
                count++;
                placed=position[i];
            }
            if(count==m)
            {
                return true;
            }
        }
        return false;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int s=1;
        int e=position[n-1];
        int dist=0;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(isPossibleToPlace(position,mid,m))
            {
               dist=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return dist;
        
    }
};