class Solution {
public:
    int f(string str,vector<int> &arr){

        int sum = 0;
        for(int i=0;i<str.size();i++){
            sum += arr[str[i]-'a'];
        }

        sum = sum % 26;
        return sum;
    }
    
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        string ans = "";
        for(auto x : words){
            int val = f(x,weights);

            char ch = 'z' - val;

            ans += ch;
        }

        return ans;
    }
};
