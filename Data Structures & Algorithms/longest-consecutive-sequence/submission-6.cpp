//brute force
/*class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0,j;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int flag=1;
            int len=1;
            int next=x+1;
            while(flag==1){
                int found=0;
                for(j=0;j<n;j++){
                    if(nums[j]==next){
                        found=1;
                        len+=1;
                        next++;
                        break;
                    }
                }
                if(found==1) flag=1;
                else flag=0;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};
*/

//better
/*class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(), nums.end()); 
        // consecutive numbers appear next to each othe
        int maxlen = 1;
        int len = 1;

        for(int i = 0; i < n; i++){
            
            if(nums[i] == nums[i+1] - 1){
                // consecutive
                len++;
            }
            else if(nums[i] == nums[i+1]){
                // duplicate → ignore
                continue;
            }
            else{
                // sequence breaks
                maxlen = max(maxlen, len);
                len = 1;
            }
        }

        maxlen = max(maxlen, len);
        return maxlen;
    }
};
*/

//optimal-set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        //Convert array → set
        unordered_set <int> s(nums.begin(), nums.end());
        for(auto &x :s){
            //Is it the START of a consecutive sequence
            if(s.count(x-1)==0){
                int next=x+1;
                int len=1;
                while(s.count(next)!=0){
                    next++;
                    len++;
                }
             maxlen=max(maxlen,len);
            }
        }

    return maxlen;
    }
};
