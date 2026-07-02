class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix_prod(n, 1);
        vector<int> suffix_prod(n, 1);
        for (int i = 1; i < n; i++) {
            int j = n - i - 1;
            prefix_prod[i] = prefix_prod[i - 1] * nums[i - 1];
            suffix_prod[j] = suffix_prod[j + 1] * nums[j + 1];
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = prefix_prod[i] * suffix_prod[i];
        }
        return ans;
    }
};
