class Solution {
public:
    int numberOfSpecialChars(string word) {

        int n = word.size();

        vector<int> last_idx_of_lower(26,-1);
        vector<int> first_idx_of_upper(26,-1);

        for(int i=0;i<n;i++){
            char x = word[i];

            if(islower(x)){
                last_idx_of_lower[x-'a'] = i;
            }
            else{
                if(first_idx_of_upper[x-'A'] == -1) first_idx_of_upper[x-'A'] = i;  
            }
        }

        int count = 0;
        for(int i=0;i<26;i++){
            if(last_idx_of_lower[i] != -1 && first_idx_of_upper[i] != -1 && last_idx_of_lower[i] < first_idx_of_upper[i]){
                count++;
            }
        }
        
        return count;
    }
};
