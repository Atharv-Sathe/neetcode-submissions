class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for (int i : nums) {
            freq[i]++;
        }
        vector<pair<int, int>> freq_to_num;
        for (auto p : freq) {
            freq_to_num.push_back(pair<int, int>(p.second, p.first));
        }
        sort(freq_to_num.begin(), freq_to_num.end(), greater<>());
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(freq_to_num[i].second);
        }
        return ans;
    }
};
