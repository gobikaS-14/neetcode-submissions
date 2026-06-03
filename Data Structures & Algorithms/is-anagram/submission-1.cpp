//brute force
/*class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if(s==t) return true;
        return false;
    }
};*/

//optimal 
class Solution {
public:
    bool isAnagram(string s, string t) {
         int freq[26] = {0};//fixed size array

         for(char c:s) freq[c-'a']++;
         for(char c:t) freq[c-'a']--;
         for(int i=0;i<26;i++){
            if(freq[i]!=0) return false;
         }
         return true;
    }
};        
