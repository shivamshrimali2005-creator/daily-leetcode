// ## Approach
// 1. Find the size `n` of the input array `nums`.
// 2. Create a result vector `ans` of size `2 * n`.
// 3. Traverse from `0` to `2*n - 1`:
//    - For the first `n` positions, copy elements from `nums` in normal order.
//    - For the remaining positions, copy elements from `nums` in reverse order.
// 4. Return the final concatenated array.

// ## Time Complexity
// - **O(n)**  
// We traverse the array only once for filling `2*n` elements.

// ## Space Complexity
// - **O(n)**  
// An extra array of size `2*n` is used to store the result.

class Solution {
public:
    vector<int> concatWithReverse(vector<int>& nums) {

        int n = nums.size();
        
        vector<int> ans(2*n);
        int index = 0;
        for(int i=0;i<2*n;i++){
            if(i < n){
                ans[i] = nums[index];
                if(index < n-1) index++;
            }
            else{
                ans[i] = nums[index];
                index--;
            }
        }

        return ans;
    }
};
