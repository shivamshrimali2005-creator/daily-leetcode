class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {

        int n = s.size();

        for(int i=1;i<n;i++){
            int n1 = s[i-1] - '0';
            int n2 = s[i] - '0';
            if(abs(n1-n2) > 2) return false;
        }

        return true;
    }
};
