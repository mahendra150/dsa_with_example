class FreqStack {
public:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>groupStack;
    int maxFreq=INT_MIN;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq=max(maxFreq,freq[val]);
        groupStack[freq[val]].push(val);
        
    }
    
    int pop() {
        auto topElement=groupStack[maxFreq].top();
        groupStack[maxFreq].pop();
        freq[topElement]--;
        if(groupStack[maxFreq].size()==0)maxFreq--;
        return topElement;
        
        
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */