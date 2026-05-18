class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for (string word: strs) {
            encoded += word;
            encoded += '"';
        } 
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        string temp = "";
        for (char c: s) {
            if (c != '"') temp += c;
            else {
                decoded.push_back(temp);
                temp = "";
            }
        }
        return decoded;
    }
};
