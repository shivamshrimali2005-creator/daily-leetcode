class Solution {
public:
    struct cmp{
        bool operator()(pair<int,int> &a,pair<int,int> &b){
            if(a.first == b.first) return a.second < b.second;
            return a.first < b.first;
        }
    };

    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int n = arr.size();
        vector<pair<int,int>> v;

        for(int i=0;i<n;i++){
            v.push_back({abs(arr[i]-x),arr[i]});
        }

        sort(v.begin(),v.end(),cmp());
        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }

        sort(ans.begin(),ans.end());

        return ans;
    }
};
