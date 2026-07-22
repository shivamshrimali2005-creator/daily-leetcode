class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        vector<int> rem0,rem1,rem2;

        for(auto x : nums){
            if(x % 3 == 0) rem0.push_back(x);
            else if(x % 3 == 1) rem1.push_back(x);
            else rem2.push_back(x);
        }

        sort(rem0.begin(),rem0.end(),greater<int>());
        sort(rem1.begin(),rem1.end(),greater<int>());
        sort(rem2.begin(),rem2.end(),greater<int>());

        int ans = 0;

        // 0,0,0
        if(rem0.size() >= 3){
            ans = max(ans,rem0[0] + rem0[1] + rem0[2]);
        }

        // 1,1,1
        if(rem1.size() >= 3){
            ans = max(ans,rem1[0] + rem1[1] + rem1[2]);
        }

        // 0,1,2
        if(rem0.size() >= 1 && rem1.size() >= 1 && rem2.size() >= 1){
            ans = max(ans,rem0[0] + rem1[0] + rem2[0]);
        } 

        // 2,2,2
        if(rem2.size() >= 3){
            ans = max(ans,rem2[0] + rem2[1] + rem2[2]);
        }

        return ans;
    }
};
