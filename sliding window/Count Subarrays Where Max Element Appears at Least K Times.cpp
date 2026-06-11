class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {

        int n = nums.size();
        int max_ele = *max_element(nums.begin(),nums.end());

        int count = 0;
        int left = 0;
        long long ans = 0;

        for(int right=0;right<n;right++){
            if(nums[right] == max_ele) count++;

            while(count == k){
                ans += (n - right);
                if(nums[left] == max_ele) count--;
                left++;
            }
        }

        return ans;        
    }
};
