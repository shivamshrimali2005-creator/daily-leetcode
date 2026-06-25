class MapSum {
public:
    map<string,int> mp;
    
    MapSum() {
    }
    
    void insert(string key, int val) {
        mp[key] = val;
    }
    
    int sum(string prefix) {
        
        int size = prefix.size();
        int ans = 0;
        for(auto x : mp){
            if(prefix == x.first.substr(0,size)){
                ans += x.second;
            }
        }

        return ans;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
