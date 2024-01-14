class AllOne {
public:
    class node{
        public:
        int freq;
        node* prev;
        node* next;
        set<string> keys;
        
        node(int freq_){
            freq= freq_;
            prev= NULL;
            next= NULL;
        }
    };
    
    node* head;
    node* tail;
    unordered_map<string,node*> h;
    
    AllOne() {
        head= NULL;
        tail= NULL;
    }
    
    void inc(string key) {
        
        if(h.count(key)){
            
            auto val= h[key];
            auto nodeFreq= val->freq;
            
            auto address= val->keys.find(key);
            if(address != val->keys.end()) val->keys.erase(address);
            
            
            if(val->next==NULL){
                
             node* newNode =new node(nodeFreq+1);
                val->next= newNode;
                newNode->prev= val;
                newNode->next= NULL;
                newNode->keys.insert(key);
                tail= newNode;
                h.erase(h.find(key));
                h[key]= newNode;
            
            }
            else{
                
                node* nextNode= val->next;
                
                if(nextNode->freq - nodeFreq>1){
                    
                    node* newNode= new node(nodeFreq+1);
                    val->next= newNode;
                    newNode->prev= val;
                    newNode->next= nextNode;
                    nextNode->prev= newNode;
                    newNode->keys.insert(key);
                    h.erase(h.find(key));
                    h[key]= newNode;
                }
                else{
                    
                    nextNode->keys.insert(key);
                    h.erase(h.find(key));
                    h[key]= nextNode;
                }
            }
            
            if(val->keys.size()==0)removeNode(val);
        }
        else{
            
            if(!head){
                
            node* newNode = new node(1);
            newNode->keys.insert(key);
            head= newNode;
            tail= newNode;
            h[key]= head;
                
            }
            else{
               
                if(head->freq==1){
                    
                    head->keys.insert(key);
                    h[key]= head;
                }
                else{
                    node* newNode= new node(1);
                    newNode->keys.insert(key);
                    newNode->next= head;
                    head->prev= newNode;
                    head= newNode;
                    h[key]= newNode;
                }
            }
        }
        
    }
    
    void dec(string key) {
        
        if(!h.count(key))return;
        
        auto val= h[key];
        auto nodeFreq= val->freq;
        
        if(nodeFreq==1){
            auto address= val->keys.find(key);
            if(address != val->keys.end())val->keys.erase(address);
            
            h.erase(h.find(key));
        }
        else if(val==head){
            
            auto address= val->keys.find(key);
            if(address != val->keys.end())val->keys.erase(address);
            node* newNode= new node(nodeFreq-1);
            newNode->next= head;
            head->prev= newNode;
            newNode->keys.insert(key);
            head= newNode;
            h[key]= newNode;
        }
        else{
            auto prevNode= val->prev;
            auto address= val->keys.find(key);
            if(address != val->keys.end())val->keys.erase(address);
            
            if(nodeFreq-prevNode->freq>1){
                node* newNode= new node(nodeFreq-1);
                newNode->keys.insert(key);
                newNode->next= val;
                val->prev=newNode;
                newNode->prev= prevNode;
                prevNode->next= newNode;
                h[key]= newNode;
            }
            else{
                
                prevNode->keys.insert(key);
                h[key]= prevNode;
            }
        }
        
        if(val->keys.size()==0)removeNode(val);
            
    }
    
    string getMaxKey() {
        
        if(!head)return "";
        
        auto val= *(tail->keys.begin());
        return val;
    }
    
    string getMinKey() {
        
        if(!head)return "";
        
        auto val= *(head->keys.begin());
        return val;
    }
    
    void removeNode(node* delNode){
        
        if(delNode==head){
            
            head= head->next;
            delNode->next= NULL;
            delete(delNode);
            if(head)head->prev= NULL;
        }
        else if(delNode==tail){
            
            tail= tail->prev;
            if(tail) tail->next= NULL;
            delNode->prev= NULL;
            delete(delNode);
        }
        else{
            delNode->prev->next= delNode->next;
            delNode->next->prev= delNode->prev;
            
            delNode->next= NULL;
            delNode->prev= NULL;
        }
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */