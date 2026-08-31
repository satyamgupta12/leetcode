class LRUCache {
public:
    int capacity;
    LRUCache(int capacity) {
        this->capacity=capacity;
    }
    list<pair<int,int>>l;
    unordered_map<int,list<pair<int,int>>::iterator>mpp;
    
    int get(int key) {
        if(mpp.find(key)==mpp.end()) return -1;
        auto it = mpp[key];
        int value=it->second;
        // update list
        l.erase(it);
        l.push_front({key,value});
        mpp[key]=l.begin();
        return value;
    }
    
    void put(int key, int value) {
        if(mpp.find(key)==mpp.end()){//nhi hai add in map and aage ayega
            if(mpp.size()<capacity){
                l.push_front({key,value});
                mpp[key]=l.begin();
            }
            else{//element nhi hai aur capacity full h
                auto last= l.back();
                mpp.erase(last.first);
                l.pop_back();
                l.push_front({key,value});
                mpp[key]=l.begin();
            }
        }
        else{//hai update hogi value has me aur aage ayega
            auto it = mpp[key];
            l.erase(it);
            l.push_front({key,value});
            mpp[key]=l.begin();

        } 
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */