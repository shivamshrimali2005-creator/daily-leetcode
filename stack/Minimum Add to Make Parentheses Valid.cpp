class Solution {
public:
    int minAddToMakeValid(string s) {
        
        int count1 = 0;
        int count2 = 0;

        for(auto x : s){
            if(x == '('){
                count1++;
            }
            else{
                if(count1 == 0) count2++;
                else{
                    count1--;
                }
            }
        }

        return count1 + count2;
    }
};
