// Design a data structure that supports all following operations in average O(1) time.
// Note: Duplicate elements are allowed.
//
//
// insert(val): Inserts an item val to the collection.
// remove(val): Removes an item val from the collection if present.
// getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
//
//
//
// Example:
//
// // Init an empty collection.
// RandomizedCollection collection = new RandomizedCollection();
//
// // Inserts 1 to the collection. Returns true as the collection did not contain 1.
// collection.insert(1);
//
// // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
// collection.insert(1);
//
// // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
// collection.insert(2);
//
// // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
// collection.getRandom();
//
// // Removes 1 from the collection, returns true. Collection now contains [1,2].
// collection.remove(1);
//
// // getRandom should return 1 and 2 both equally likely.
// collection.getRandom();
//
//


class RandomizedCollection {
public:
    
    //这道题和上一道题主要思路基本相同，但不同之处在于这道题会出现重复，即map对应的数组下标可能不止一个
    //所以这里用unordered_set来存储所有出现过的相同值的下标,因此难点仍然在于如何做到数组的O(1)删除
    //注意这里的getRandom无需做特别的修改，因为均匀抽样就保证了某个数字出现的次数与其出现次数是线性相关的
    
    /** Initialize your data structure here. */
    RandomizedCollection() {}
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        //对应值的下标
        m[val].insert(nums.size());
        nums.push_back(val);
        return m[val].size() == 1;  //是否是第一次出现该值
    }
    
    //这道题主要难点在remove函数上
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if(m[val].empty()) return false;
        int index = *m[val].begin();
        m[val].erase(index);
        if(index != (nums.size()-1)) {
            //将index位置的值替换为数组末尾的值，再弹出数组末尾即可
            int tmp = nums.back();
            nums[index] = tmp;
            m[tmp].erase(nums.size()-1);
            m[tmp].insert(index);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
private:
    vector<int> nums;
    //值与其出现位置的映射
    unordered_map<int , unordered_set<int>> m;
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
