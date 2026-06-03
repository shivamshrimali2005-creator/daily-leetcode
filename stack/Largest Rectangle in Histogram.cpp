class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // LEFT SMALLER HEIGHT
        // RIGHT SMALLER HEIGHT

        int n = heights.size();

        vector<int> left(n);
        vector<int> right(n);

        stack<int> st;

        // RIGHT
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && heights[i] < heights[st.top()]){
                    right[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }

        while(!st.empty()){
            right[st.top()] = n;
            st.pop();
        }

        // LEFT
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
            }
            else{
                while(!st.empty() && heights[i] < heights[st.top()]){
                    left[st.top()] = i;
                    st.pop();
                }
                st.push(i);
            }
        }

        while(!st.empty()){
            left[st.top()] = -1;
            st.pop();
        }

        int ans = -1;
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i] * (right[i] - left[i] -1));
        }

        return ans;
    }
};
