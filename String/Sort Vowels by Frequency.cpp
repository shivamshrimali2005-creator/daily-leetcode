class Solution {
public:
    bool isvowel(char ch){
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    string sortVowels(string s) {

        vector<pair<char,int>> freq;
        vector<int> index(26,-1);

        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                char ch = s[i];

                bool flag = false;
                for(auto &x : freq){
                    if(x.first == ch){
                        x.second++;
                        flag = true;
                    }
                }

                if(!flag){
                    freq.push_back({ch,1});
                    index[ch-'a'] = i;
                }
            }
        }

        sort(freq.begin(),freq.end(),
        [&](pair<char,int> &a,pair<char,int> &b){
            if(a.second != b.second) return a.second > b.second;
            else{
                return index[a.first-'a'] < index[b.first-'a'];
            }
        }
        );

        string temp = "";
        for(auto x : freq){
            temp += string(x.second,x.first);
        }

        int j=0;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                s[i] = temp[j];
                j++;
            }
        }
        
        return s;
    }
};
