class Solution {
public:
    int characterReplacement(string s, int k) {
     int hash[26]={0};
     int l=0,r=0,maxfreq=0,maxlen=0;
     int n=s.size();

     while(r<n){
        hash[s[r]-'A']++;
        maxfreq=max(maxfreq,hash[s[r]-'A']);
        int len=r-l+1;
        int changes=len-maxfreq;
        if(changes>k){
            hash[s[l]-'A']--;
            l++;
        }
        else{
        maxlen=max(maxlen,len);}
        r++;
     }
     return maxlen;
    }
};
