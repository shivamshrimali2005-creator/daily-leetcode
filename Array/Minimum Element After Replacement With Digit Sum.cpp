class Solution {
public:
    int f(int n){
        int s = 0;
        while(n > 0){
            int digit = n % 10;
            s += digit;
            n = n / 10;
        }

        return s;
    }

    int minElement(vector<int>& nums) {
        
        int mini = INT_MAX;

        for(int i=0;i<nums.size();i++){
            int sum_of_digit = f(nums[i]);
            mini = min(mini,sum_of_digit);
        }

        return mini;
    }
};
