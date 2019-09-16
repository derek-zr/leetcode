// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//
// Note that the number of times an item is used is the number of calls to the get and put functions for that item since it was inserted. This number is set to zero when the item is removed.
//
//  
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
//  
//
// Example:
//
//
// LFUCache cache = new LFUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4
//
//
//  
//


class LFUCache {
public:
    LFUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(m.count(key) == 0) return -1;
        //从当前freq list中删除该元素
        freq[m[key].second].erase(iter[key]);
        //增加freq
        ++m[key].second;
        freq[m[key].second].push_back(key);
        iter[key] = --freq[m[key].second].end();  //刚刚push进去，在尾部(end指向最后一个元素的下一个)
        if(freq[minFreq].empty()) ++minFreq;
        return m[key].first;
    }
    
    void put(int key, int value) {
        //错误判断
        if(cap <= 0) return;
        //先get key。这里需要调用get(key),而不是直接判断。因为put也相当于一次访问，需要改变freq
        if(get(key) != -1) {  //已经有这个key了
            m[key].first = value;
            return;
        }
        if(m.size() >= cap) {
            //去除最不常用的
            m.erase(freq[minFreq].front());
            iter.erase(freq[minFreq].front());
            freq[minFreq].pop_front();
        }
        //插入
        m[key] = {value , 1};
        freq[1].push_back(key);
        iter[key] = --freq[1].end();
        //最小频率重置为1
        minFreq = 1;
    }

private:
    int cap, minFreq;  //最小频率
    //key,<value,freqs>
    unordered_map<int,pair<int,int>> m;
    //freq,list 该list内的key出现了freq次
    unordered_map<int,list<int>> freq;
    //key,iterator key对应的list
    unordered_map<int,list<int>::iterator> iter;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
