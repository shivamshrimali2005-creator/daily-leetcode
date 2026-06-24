class Solution {
public:
    string removeDuplicateLetters(string s) {
        
        int n = s.size();
        string result = "";

        vector<int> lastindex(26);
        vector<int> taken(26,false);

        for(int i=0;i<n;i++){
            lastindex[s[i]-'a'] = i;
        }

        for(int i=0;i<n;i++){
            char ch = s[i];

            if(taken[ch-'a'] == true) continue;

            while(result.size() > 0 && result.back() > ch && lastindex[result.back() - 'a'] > i){
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }
            
            result.push_back(ch);
            taken[ch - 'a'] = true;
        }

        return result;
    }
};
