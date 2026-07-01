class Solution {
public:
    string alphabetBoardPath(string target) {

        string ans = "";
        int curr_row = 0;
        int curr_col = 0;

        for(int i=0;i<target.size();i++){

            int target_row = (target[i] - 'a') / 5;
            int target_col = (target[i] - 'a') % 5;

            while(curr_row > target_row){
                ans += 'U';
                curr_row--;
            }

            while(curr_col > target_col){
                ans += 'L';
                curr_col--;
            }

            while(curr_row < target_row){
                ans += 'D';
                curr_row++;
            }

            while(curr_col < target_col){
                ans += 'R';
                curr_col++;
            }

            ans += '!';
        }

        return ans;
    }
};
