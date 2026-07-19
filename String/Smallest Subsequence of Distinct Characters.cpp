class Solution {
public:
    string smallestSubsequence(string s) {

        int n = s.size();
        string ans = "";

        vector<int> lastindex(26);
        vector<int> taken(26,0);

        for(int i=0;i<n;i++){
            lastindex[s[i]-'a'] = i;
        }

        for(int i=0;i<n;i++){
            char ch = s[i];

            if(taken[ch-'a'] == 1) continue;

            while(ans.size() > 0 && ans.back() > ch && lastindex[ans.back()-'a'] > i){
                taken[ans.back()-'a'] = 0;
                ans.pop_back();
            }
            
            ans += ch;
            taken[ch-'a'] = 1;
        }

        return ans;
    }
};
