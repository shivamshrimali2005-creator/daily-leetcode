class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        int num = text.size();
        vector<int> freq(26,0);

        for(char x : text){
            freq[x-'a']++;
        }

        int b = freq['b'-'a'];
        int a = freq['a'-'a'];
        int l = freq['l'-'a']/2;
        int o = freq['o'-'a']/2;
        int n = freq['n'-'a'];

        return min({b,a,l,o,n});
    }
};
