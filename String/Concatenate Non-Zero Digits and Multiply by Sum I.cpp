class Solution {
public:
    long long sumAndMultiply(int n) {

        string str = to_string(n);

        long long sum = 0;
        long long x = 0;
        long long pow = 1;
        
        for(int i=str.size()-1;i>=0;i--){
            if(str[i] != '0'){
                sum += (str[i]-'0');

                x = x + pow * (str[i]-'0');
                pow = pow * 10;
            }   
        }
        
        return x * sum;
    }
};
