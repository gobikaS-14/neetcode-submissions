class Solution {
public:
    bool isPalindrome(string s) {
        string clean = "";
for(char c : s) {
    if(isalnum(c)) clean += tolower(c);
}
string rev_clean = clean;
reverse(rev_clean.begin(), rev_clean.end());
return clean == rev_clean;


    }
};
