class MyHashMap {
public:
    vector<pair<bool,int>> hash_map;
    MyHashMap() {
        hash_map=vector<pair<bool,int>>(1000001,{false,0});
    }
    
    void put(int key, int value) {
        hash_map[key]= {true, value};
    }
    
    int get(int key) {
        if(hash_map[key].first){
            return hash_map[key].second;
        }
        return -1;
    }
    
    void remove(int key) {
        hash_map[key].first= false;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */