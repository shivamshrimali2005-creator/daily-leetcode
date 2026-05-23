class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n;i++){
            if(i == 0){
                if(nums[n-1] > nums[0]) count++;
            }
            else{
                if(nums[i-1] > nums[i]) count++;
            }
        }

        return count <= 1;
    }
};
