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

        vector<int> freq1(26,0),freq2(26,0);

        //freq count of s1
        for(char c:s1) freq1[c-'a']++;
 
        
        for(int i = 0; i < n2; i++) {
            freq2[s2[i]-'a']++;

            if(i >= n1) {
                freq2[s2[i-n1]-'a']--;
            }

            if(i >= n1 - 1) {
                if(freq1 == freq2) return true;
            }
        }
        return false;
    }
};
