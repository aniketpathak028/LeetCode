class MyHashSet {
public:
    vector<bool> data;
    MyHashSet() {
        data = vector<bool>(1000001, false);
    }
    
    void add(int key) {
        data[key] = true;
    }
    
    void remove(int key) {
        data[key] = false;
    }
    
    bool contains(int key) {
        if(data[key]) return true;
        else return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */