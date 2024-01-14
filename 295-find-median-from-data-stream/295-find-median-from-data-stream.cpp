class MedianFinder {
public:
    priority_queue<int,vector<int>,greater<int>>right;
    priority_queue<int>left;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.size()==0)
        {
            left.push(num);
        }
        else
        {
            double mid=findMedian();
            if(left.size()>right.size())
            {
                if(num>mid)
                {
                right.push(num);
                }
                else
                {
                    right.push(left.top());
                    left.pop();
                    left.push(num);
                }
            }
            else if(right.size()>left.size())
            {
                if(num<mid)
                {
                    left.push(num);
                }
                else
                {
                    left.push(right.top());
                    right.pop();
                    right.push(num);
                }
            }
            else
            {
                if(num<mid)
                {
                    left.push(num);
                }
                else 
                {
                    right.push(num);
                }
            }
        }
        
    }
    
    double findMedian() {
       if(left.size()>right.size())
       {
           return double(left.top());
       }
        else  if(right.size()>left.size())
        {
            return double(right.top());
        }
            return ((double(left.top())+double(right.top()))/2);
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */