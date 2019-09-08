// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//
// The cache is initialized with a positive capacity.
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
//
// LRUCache cache = new LRUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.put(4, 4);    // evicts key 1
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
//
//
//  
//


class LRUCache {
public:
    LRUCache(int capacity):cap(capacity) {
        
    }
    
    int get(int key) {
        if(m.find(key) == m.end()) 
        {
            return -1;
        }
        else {
            touch(m[key]);
            return l.begin()->second;
        }
        
    }
    
    void put(int key, int value) {
        if(m.find(key) != m.end()) {
            //OR l.splice(l.begin(),l,m[key])
            touch(m[key]);
            l.begin()->second = value;
        }
        else {
            if(m.size() == cap) {
                int be_del = l.back().first;
                m.erase(be_del);
                l.pop_back();
            }
            //cout<<key<<value<<endl;
            l.push_front({key,value});
            m[key] = l.begin();
        }
    }

private:
    typedef std::list<std::pair<int,int>> PLIST;
    
    int cap;
    PLIST l;
    std::unordered_map<int,PLIST::iterator> m;
    
    //取代STL内置的splice函数。自己实现O(1)的操作
    void touch(PLIST::iterator it) {
        int key = it->first;
        int value = it->second;
        l.erase(it);
        l.push_front({key,value});
        m[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
