// # 2553. Separate the Digits in an Array

// ## Approach
// - Traverse each number in the array.
// - Convert the number into a string.
// - Iterate through every character of the string.
// - Convert each character back to an integer digit and store it in the answer array.
// - Return the final array containing all separated digits in order.

// ## Time Complexity
// - **O(N × D)**  
// Where:
// - `N` = number of elements in `nums`
// - `D` = number of digits in each number

// ## Space Complexity
// - **O(N × D)**  
// For storing the separated digits in the result array.

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        vector<int> ans;

        for(int i=0;i<nums.size();i++){
            string str = to_string(nums[i]);
            for(int j=0;j<str.size();j++){
                ans.push_back(str[j]-'0');
            }
        }

        return ans;
    }
};

  
