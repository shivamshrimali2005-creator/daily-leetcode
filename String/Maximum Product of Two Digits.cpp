class Solution {
public:
    int maxProduct(int n) {
        
        string str = to_string(n);
        int size = str.size();

        sort(str.begin(),str.end());

        return (str[size-1]-'0') * (str[size-2]-'0');
    }
};
