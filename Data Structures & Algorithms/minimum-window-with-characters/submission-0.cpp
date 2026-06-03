class Solution {
public:
    string minWindow(string s, string t) {
        string ans = "";
        int minLen = INT_MAX;

        for (int i = 0; i < s.size(); i++) {
            string substr = "";

            for (int j = i; j < s.size(); j++) {
                substr.push_back(s[j]);

                bool valid = true;
                for (char a : t) {
                    if (count(substr.begin(), substr.end(), a) <
                        count(t.begin(), t.end(), a)) {
                        valid = false;
                        break;
                    }
                }

                if (valid) { // valid window
                    if (substr.size() < minLen) {
                        minLen = substr.size();
                        ans = substr;
                    }
                    break; // shortest for this i
                }
            }
        }
        return ans;
    }
};
