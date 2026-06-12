class Solution {
public:
    string minWindow(string s, string t) {
        
        unordered_map<char,int> mp;
        for(auto x : t){
            mp[x]++;
        }

        int n = s.size();
        int left = 0;
        int total = t.size();
        int minlen = INT_MAX;
        int index = -1;

        for(int right=0;right<n;right++){
            mp[s[right]]--;
            if(mp[s[right]] >= 0) total--;

            while(!total){
                if(minlen > right - left + 1){
                    minlen = right - left + 1;
                    index = left;
                }

                mp[s[left]]++;
                if(mp[s[left]] > 0) total++;
                left++;
            }
        }

        return minlen == INT_MAX ? "" : s.substr(index,minlen);
    }
};
