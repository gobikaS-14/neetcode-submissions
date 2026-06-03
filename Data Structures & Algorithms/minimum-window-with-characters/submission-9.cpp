//brute force
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
    int minLen = INT_MAX;
    string ans = "";

    for(int i = 0; i < n; i++) {

        vector<int> freq(128, 0);

        for(int j = i; j < n; j++) {

            freq[s[j]]++;

            vector<int> need(128, 0);
            for(char c : t) need[c]++;

            bool ok = true;
            for(int k = 0; k < 128; k++) {
                if(freq[k] < need[k]) {
                    ok = false;
                    break;
                }
            }

            if(ok) {
                if(j - i + 1 < minLen) {
                    minLen = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
                break;
            }
        }
    }

    return ans;
    }
};
