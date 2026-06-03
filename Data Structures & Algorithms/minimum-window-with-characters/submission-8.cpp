//optimal
//striver-https://youtu.be/WJaij9ffOIY
class Solution {
public:
    string minWindow(string s, string t) {
        
        //fill need using t
        vector<int> need(128,0);
        for(char c:t)   need[c]++;

        int req=0;
        int start=-1,minlen=INT_MAX,left=0;
        int right=0;
        while(right<s.size()){
            if(need[s[right]]>0)    req++;
            need[s[right]]--;//its need  reduced 

            while(req==t.size()){
                if(right-left+1 <minlen){
                    minlen =right-left+1;
                    start=left;
                }
                //shrink
                need[s[left]]++;
                if(need[s[left]]>0)    req--;
                left++;
            }
            right++;
        }
        return minlen==INT_MAX? "" : s.substr(start,minlen);
     }
};