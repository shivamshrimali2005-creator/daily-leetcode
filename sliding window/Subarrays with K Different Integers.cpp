class Solution {
public:
    int f(vector<int> &nums,int k){

        int n = nums.size();
        unordered_map<int,int> mp;

        int left = 0;
        int count = 0;

        int ans = 0;

        for(int right=0;right<n;right++){
            mp[nums[right]]++;
            if(mp[nums[right]] == 1) count++;

            while(count == k){
                ans += n - right;
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) count--;
                left++;
            }
        }

        return ans;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // EXACTLY (K) = ATLEAST (K) - ATLEAST (K-1)
        return f(nums,k) - f(nums,k+1);   
    }
};
