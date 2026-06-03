class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if(n1 > n2) return false;

        // Sort s1 once
        string sortedS1 = s1;
        sort(sortedS1.begin(), sortedS1.end());

        // Check every window of length n1
        for(int i = 0; i <= n2 - n1; i++) {
            string sub = s2.substr(i, n1);  // take substring of same length
            sort(sub.begin(), sub.end());   // sort it

            if(sub == sortedS1) {
                return true;
            }
        }

        return false;
    }
};
