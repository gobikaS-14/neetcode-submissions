class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[256] = {0};   // freq of all ASCII characters
        int maxFreq = 0;       // highest frequency in window
        int left = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {

            hash[s[right]]++;                         // add current char to window
            maxFreq = max(maxFreq, hash[s[right]]);   // update max freq in window

            int windowSize = right - left + 1;

            // if we need more than k replacements → shrink window
            if (windowSize - maxFreq > k) {
                hash[s[left]]--;                      // remove left char
                left++;                               // shrink window
            }

            ans = max(ans, right - left + 1);         // update best answer
        }

        return ans;
    }
};
