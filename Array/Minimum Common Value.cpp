class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        
        set<int> s;
        for(int x : nums1){
            s.insert(x);
        }

        for(int x : nums2){
            if(s.find(x) != s.end()) return x;
        }
        return -1;
    }
};
