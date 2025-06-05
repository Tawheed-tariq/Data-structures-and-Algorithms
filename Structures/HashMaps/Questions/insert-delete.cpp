class RandomizedSet {
    unordered_map<int, int> set;
    vector<int> v;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(set.find(val) != set.end())
            return false;
        v.push_back(val);
        set[val] = v.size() - 1;
        return true;
    }
    
    bool remove(int val) {
        if(!(set.find(val) != set.end()))
            return false;

        auto it = set.find(val); 
        v[it->second] = v.back(); //change value at this index to value at back
        v.pop_back(); //remove last element
        set[v[it->second]] = it->second; //update index of this ele in set
        set.erase(val);
        return true;
    }
    
    int getRandom() {
        return v[rand()%v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */