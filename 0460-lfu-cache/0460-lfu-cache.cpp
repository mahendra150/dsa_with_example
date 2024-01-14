struct Node{
    int key,value,count;
    Node* next;
    Node* prev;
    Node(int _key,int _value){
        key= _key;
        value= _value;
        count=1;
    }
};

struct List{
    int size;
    Node* head;
    Node* tail;
    List(){
        head= new Node(0,0);
        tail= new Node(0,0);
        head->next= tail;
        tail->prev= head;
        size=0;
    }
    
    void addFront(Node* node){
        Node* temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }
    
    void removeNode(Node* delNode){
        Node* delNext= delNode->next;
        Node* delPrev= delNode->prev;
        
        delPrev->next= delNext;
        delNext->prev= delPrev;
        size--;
    }
};
class LFUCache {
public:
    map<int,Node*> h;
    map<int,List*> freqListMap;
    
    int maxSizeCache;
    int minFreq;
    int currSize;
    
    LFUCache(int capacity) {
        maxSizeCache= capacity;
        currSize=0;
        minFreq=0;
    }
    
    void updateFreqListMap(Node* node){
        
        h.erase(node->key);
        freqListMap[node->count]->removeNode(node);
        if(node->count==minFreq and freqListMap[node->count]->size==0){
            minFreq++;
        }
        
        List* nextHigherFreqList= new List();
        if(freqListMap.find(node->count+1) != freqListMap.end()){
            nextHigherFreqList= freqListMap[node->count+1];
        }
        
        node->count+=1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->count]= nextHigherFreqList;
        h[node->key]= node;
    }
    
    int get(int key) {
        
        if(h.find(key) != h.end()){
            
            Node* node= h[key];
            auto val= node->value;
            updateFreqListMap(node);
            return val;
        }
        
        return (-1);
    }
    
    void put(int key, int value) {
        if(maxSizeCache==0)return;
        
        if(h.find(key) != h.end()){
            
            Node* node=h[key];
            node->value= value;
            updateFreqListMap(node);
        }
        else{
            if(currSize==maxSizeCache){
                
                List* list= freqListMap[minFreq];
                h.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }
            
            currSize++;
            minFreq= 1;
            List* listFreq= new List();
            if(freqListMap.find(minFreq) != freqListMap.end()){
                listFreq=freqListMap[minFreq];
            }
            
            Node* node= new Node(key,value);
            listFreq->addFront(node);
            freqListMap[minFreq]= listFreq;
            h[key]= node;
            
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */