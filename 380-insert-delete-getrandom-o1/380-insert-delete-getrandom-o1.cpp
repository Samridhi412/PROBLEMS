class RandomizedSet {
    unordered_map<int,int> mp;
    vector<int> arr;
public:
    RandomizedSet() {
        mp.clear();
        arr.clear();
    }
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end()){
            return false;
        }
        mp[val]=arr.size();
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end()){
            return false;
        }
        int ind=mp[val];
        mp[arr[arr.size()-1]]=ind;
        swap(arr[arr.size()-1],arr[ind]);
        arr.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int idx=rand()%arr.size();
        return arr[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */