class Solution {
public:
    bool isGood(vector<int>& nums) {

        int maxi = *max_element(nums.begin(),nums.end());

        if(nums.size() != maxi + 1) return false;

        vector<int> freq(maxi+1,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }

        for(int i=1;i<freq.size();i++){
            if(i == maxi){
                if(freq[i] != 2) return false;
            }
            else{
                if(freq[i] != 1) return false;
            }
        }

        return true;
    }
};
