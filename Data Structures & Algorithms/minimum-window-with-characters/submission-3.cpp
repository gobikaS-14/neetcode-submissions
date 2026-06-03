class Solution {
public:
    string minWindow(string s, string t) {
        
        //fill need using t
        vector<int> need(128,0);
        for(char c:t)   need[c]++;

        int req=t.size();
        int start=0,minlen=INT_MAX,left=0;
        for(int right=0;right<s.size();right++){
            ///expand right, one char at a time
            //if right char is still needed then we have seen it so req--;
            if(need[s[right]]>0)    req--;
            need[s[right]]--;//its need also reduced 

            while(req==0){
                if(right-left+1 <minlen){
                    minlen =right-left+1;
                    start=left;
                }
                //shrink
                need[s[left]]++;
                if(need[s[left]]>0)    req++;
                left++;
            }

        }
        return minlen==INT_MAX? "" : s.substr(start,minlen);
     }
};