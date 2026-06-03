/*brute force

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) return false;

        // Sort s1 once
        
        sort(s1.begin(), s1.end());

        // Check every window of length n1
        for(int i = 0; i <= n2 - n1; i++) {
            string sub = s2.substr(i, n1);  // take substring of same length
            sort(sub.begin(), sub.end());   // sort it

            if(sub == s1) {
                return true;
            }
        }

        return false;
    }
};
*/

//optimal 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        

        vector<int> freq1(26, 0), freq2(26, 0);

        // Frequency of s1
        for (char c : s1)
            freq1[c - 'a']++;

        // First window of s2
        for (int i = 0; i < n1; i++)
            freq2[s2[i] - 'a']++;

        // Check first window
        if (freq1 == freq2) return true;

        // Slide the window
        for (int i = n1; i < n2; i++) {

            // Add new char into window
            freq2[s2[i] - 'a']++;

            // Remove char that leaves window
            freq2[s2[i - n1] - 'a']--;

            // Compare
            if (freq1 == freq2) return true;
        }

        return false;
    }
};
