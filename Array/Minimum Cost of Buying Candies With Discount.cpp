class Solution {
public:
    int minimumCost(vector<int>& cost) {

        sort(cost.begin(),cost.end());

        int ans = 0;
        int i = cost.size()-1;

        int f = 0;
        while(i >= 0){
            ans += cost[i];
            i--;
            f++;
            if(f == 2){
                i--;
                f = 0;
            }
        }

        return ans;
    }
};
