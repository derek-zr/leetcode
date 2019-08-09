// Implement a data structure supporting the following operations:
//
//
//
// Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
// Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
// GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
// GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
//
//
//
//
// Challenge: Perform all these in O(1) time complexity.
//


class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() {}
    
    //建立一个bucket链表，每一个bucket存储value和这个value对应的keys
    //同时建立一个key和bucket位置的映射关系，使得能够在O(1)时间内快速找到对应的链表位置
    //这样能够方便快速得到最大key和最小key（即链表头部和尾部对应的key）
    //数据格式如下：
    /*
    l0: val = 4, keys = {"A", "B"}
    l1: val = 2, keys = {"C"}
    l2: val = 1, keys = {"D"}
    */
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        //如果key没出现过，则先插入
        if(!indexOfKey.count(key)) {
            //insert返回的是指向第一个新插入元素位置的迭代器
            //这里先插入0，方便后续统计做加法操作
            indexOfKey[key] = buckets.insert(buckets.begin(),{0,{key}});
        }
        auto cur = indexOfKey[key], n = next(cur);
        //判断+1后的value值是否存在，不存在则创建
        //先判断是否溢出了
        if(n == buckets.end() || n->value > cur->value+1) {
            //insert是插入到当前所指的迭代器之前
            n = buckets.insert(n,{cur->value+1,{}});
        }
        n->keys.insert(key);
        indexOfKey[key] = n;
        //删除key和空的bucket
        cur->keys.erase(key);
        if(cur->keys.empty()) {
            buckets.erase(cur);
        }
        //cout<<n->value<<*(n->keys.begin());
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        //不存在key则直接返回
        if(!indexOfKey.count(key)) return;
        auto cur = indexOfKey[key], pre = cur==buckets.begin() ? cur : prev(cur);
        indexOfKey.erase(key);
        //判断减1后的value是否存在
        if(cur->value > 1) {
            if(cur==buckets.begin() || pre->value < cur->value-1) {
                pre = buckets.insert(cur,{cur->value-1,{}});
            }
            pre->keys.insert(key);
            indexOfKey[key] = pre;
        }
        //删除
        cur->keys.erase(key);
        if(cur->keys.empty()) {
            buckets.erase(cur);
        }
        //cout<<pre->value<<*(pre->keys.begin());
        //cout<<*(buckets.begin()->keys.begin())<<buckets.begin()->value<<*(buckets.rbegin()->keys.begin())<<buckets.rbegin()->value;
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        //结构体指针访问成员：->keys
        //访问迭代器指向的内容
        //end()指向最后一个元素的下一个，rbegin()指向最后一个元素
        //cout<<*(buckets.begin()->keys.begin())<<buckets.begin()->value<<*(buckets.rbegin()->keys.begin())<<buckets.rbegin()->value;
        return buckets.empty() ? "" : *(buckets.rbegin()->keys.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *(buckets.begin()->keys.begin());
    }

private:
    struct Bucket{int value; unordered_set<string> keys;};
    list<Bucket> buckets;
    //某一个key对应的链表中的位置
    unordered_map<string, list<Bucket>::iterator> indexOfKey;
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */
