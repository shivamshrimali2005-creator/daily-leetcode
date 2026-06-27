class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {

        vector<int> ans;
        int index = num.size()-1;
        int carry = 0;

        while(k > 0 && index >= 0){
            int sum = num[index] + (k % 10) + carry;
            k = k / 10;
            index--;
            carry = sum / 10;
            ans.push_back(sum % 10);
        }

        if(k == 0){
            while(index >= 0){
                int sum = num[index] + carry;
                ans.push_back(sum % 10);
                carry = sum / 10;
                index--;
            }
        }
        else{
            while(k > 0){
                int sum = k%10 + carry;
                ans.push_back(sum % 10);
                carry = sum / 10;
                k = k / 10;
            }
        }
        if(carry) ans.push_back(carry);

        reverse(ans.begin(),ans.end());

        return ans;
    }
};
