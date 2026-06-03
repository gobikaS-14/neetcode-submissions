/*
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
};*/


class Solution {
public:
string minWindow(string s, string t) {
    if (s.empty() || t.empty()) return "";

    vector<int> need(128, 0);  // frequency of chars in t
    for (char c : t) need[c]++;

    int required = t.size();
    int left = 0, minLen = INT_MAX, start = 0;

    for (int right = 0; right < s.size(); right++) {
        if (need[s[right]] > 0) required--;
        need[s[right]]--;

        while (required == 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                start = left;
            }

            need[s[left]]++;
            if (need[s[left]] > 0) required++;
            left++;
        }
    }

    return minLen == INT_MAX ? "" : s.substr(start, minLen);
}

};