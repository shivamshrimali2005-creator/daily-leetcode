class Solution {
public:
    TreeNode *f(vector<int> &nums,int &index,int start,int end){

        if(start > end) return NULL;

        int mid = start + (end - start) / 2;

        TreeNode *root = new TreeNode(nums[mid]);
        index++;

        root->left = f(nums,index,start,mid-1);
        root->right = f(nums,index,mid+1,end);

        return root;
    }


    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int n = nums.size();
        int start = 0;
        int end = n-1;
        int index = 0;

        return f(nums,index,start,end);
    }
};
