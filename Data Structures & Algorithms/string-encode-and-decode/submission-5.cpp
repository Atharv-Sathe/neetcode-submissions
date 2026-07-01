class Solution {
public:

    string encode(vector<string>& strs) {
        string code = "";
        for (string s : strs) {
            code += to_string(s.length()) + '_' + s;
        }
        return code;
    }

    vector<string> decode(string s) {
        if (s.empty()) {
            return {};
        }
        vector<string> ans;
        int i = 0;
        while (i < s.size()) {
            string len = "";
            while(s[i] != '_') {
                len += s[i];
                i++;
            }

            int str_len = stoi(len);
            string word = s.substr(i + 1, str_len);            
            ans.push_back(word);
            i += str_len + 1;
        }
        return ans;
    }
};
