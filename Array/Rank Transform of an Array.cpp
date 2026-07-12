class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        int n = arr.size();

        vector<int> copy = arr;
        sort(copy.begin(),copy.end());

        map<int,int> mp;

        int rank = 1;
        for(int i=0;i<n;i++){
            if(!mp.count(copy[i])){
                mp[copy[i]] = rank;
                rank++;
            }
        }

        vector<int> ans;

        for(auto x : arr){
            ans.push_back(mp[x]);
        }

        return ans;
    }
};
