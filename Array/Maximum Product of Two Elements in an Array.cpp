class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int max = INT_MIN;
        int secmax = INT_MIN;

        for(int i=0;i<nums.size();i++){
            if(max < nums[i]){
                secmax = max;
                max = nums[i];
            }
            else if(secmax < nums[i]){
                secmax = nums[i];
            }
        }
        return (max - 1) * (secmax - 1);
    }
};
