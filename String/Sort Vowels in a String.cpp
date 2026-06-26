class Solution {
public:
    string sortVowels(string s) {
        
        int n = s.size();

        vector<int> lower(26,0);
        vector<int> upper(26,0);

        for(int i=0;i<n;i++){
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'){
                lower[s[i]-'a']++;
                s[i] = '#';
            }
            else if(s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'){
                upper[s[i]-'A']++;
                s[i] = '#';
            }
        }
        string all_vowel = "";

        for(int i=0;i<26;i++){
            all_vowel += string(upper[i],i+'A');
        }

        for(int i=0;i<26;i++){
            all_vowel += string(lower[i],i+'a');
        }

        string ans = "";
        int index = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '#'){
                ans += all_vowel[index];
                index++;
            }
            else ans += s[i];
        }

        return ans;
    }
};
