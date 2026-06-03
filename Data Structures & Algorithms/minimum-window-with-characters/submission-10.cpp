//brute force
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        int minLen = INT_MAX;
        int sIndex = -1;

        for(int i = 0; i < n; i++) {

            vector<int> hash(256, 0);
            int cnt = 0;
            for(char c:t)   hash[c]++;

            // build window
            for(int j = i; j < n; j++) {
                if(hash[s[j]]>0)  cnt++;
                 hash[s[j]]--;

                // when all characters matched
                if(cnt == m) {

                    if(j - i + 1 < minLen) {
                        minLen = j - i + 1;
                        sIndex = i;
                    }
                    break;
                }
            }
        }

        return (sIndex == -1) ? "" : s.substr(sIndex, minLen);

    }
};