class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hash(256,-1);
        int n=s.size();
        int l=0,r=0,maxlen=0;

        while(r<n){
            //check is s[r] is a repeating char
            //ensure s[r] is repeated only within currently considered substring
            if(hash[s[r]]!=-1 && hash[s[r]]>=l){
                l=hash[s[r]]+1;
            }
            else{
                int len=r-l+1;
                maxlen=max(maxlen,len);
            }
            hash[s[r]]=r;//
            r++;
        }
        return maxlen;
    }
};
