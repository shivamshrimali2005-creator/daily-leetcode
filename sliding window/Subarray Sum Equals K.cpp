class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;

        int ans = 0;
        int prefix_sum = 0;

        for(int i=0;i<n;i++){
            prefix_sum += nums[i];
            if(mp.count(prefix_sum - k)){
                ans += mp[prefix_sum - k];
                mp[prefix_sum]++;
            }
            else{
                mp[prefix_sum]++;
            }
        }

        return ans;
    }
};
