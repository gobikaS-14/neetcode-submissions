//brute force
/*class Solution {
public:
    bool isPalindrome(string s) {
        //Remove spaces, punctuation.
        //Convert all letters to lowercase.
        string clean = "";
        for(char c : s) {
            if(isalnum(c)) clean += tolower(c);
        }
        string rev_clean = clean;
        reverse(rev_clean.begin(), rev_clean.end());
        return clean == rev_clean;
  }
};*/

//optimal-2 pointer
class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;

        while(i<j){
            while(i<j && !(isalnum(s[i]))) i++;
            while(i<j && !(isalnum(s[j]))) j--;
            if( tolower(s[i]) != tolower(s[j]) ) {
                return false;
            }
            i++;
            j--;
        }
        return true;

    }
};        
