class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // unordered_map<int, int> freq;
        // for (int i : nums) {
        //     freq[i]++;
        // }
        // vector<pair<int, int>> freq_to_num;
        // for (auto p : freq) {
        //     freq_to_num.push_back(pair<int, int>(p.second, p.first));
        // }
        // sort(freq_to_num.begin(), freq_to_num.end(), greater<>());
        // vector<int> ans;
        // for (int i = 0; i < k; i++) {
        //     ans.push_back(freq_to_num[i].second);
        // }
        // return ans;

        vector<int> freq(2001, 0);
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i] + 1000]++;
        }

        priority_queue<pair<int, int>> pq;
        for (int i = 0; i < 2001; i++) {
            if (!freq[i]) continue;
            pq.push(pair<int, int>(freq[i], i - 1000));
        }

        vector<int> ans;
        while(k--) {
            auto [freq, num] = pq.top();
            pq.pop();
            ans.push_back(num);
        }
        return ans;
    }
};
