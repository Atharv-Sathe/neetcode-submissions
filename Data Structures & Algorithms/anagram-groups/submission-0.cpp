class Solution {
private:
    bool isAnagram(string& s1, string& s2) {
        int len_s1 = s1.length();
        int len_s2 = s2.length();
        if (len_s1 != len_s2) {
            return false;
        }

        unordered_map<char, int> freq;
        for (int i = 0; i < len_s1; i++) {
            freq[s1[i]]++;
            freq[s2[i]]--;
            if (!freq[s1[i]]) {
                freq.erase(s1[i]);
            }
            if (!freq[s2[i]]) {
                freq.erase(s2[i]);
            }
        }
        
        return freq.empty();
    }
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_set<string> visited;
        vector<vector<string>> anagrams;
        for (int i = 0; i < strs.size(); i++) {
            if (visited.count(strs[i])) continue;
            visited.insert(strs[i]);
            vector<string> temp;
            temp.push_back(strs[i]);
            for (int j = i + 1; j < strs.size(); j++) {
                if (isAnagram(strs[i], strs[j])) {
                    temp.push_back(strs[j]);
                    visited.insert(strs[j]);
                }
            }
            anagrams.push_back(temp);
        }
        return anagrams;
    }
};
