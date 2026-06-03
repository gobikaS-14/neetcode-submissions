
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
            //Instead of starting from every element and repeatedly checking sequences, we only start from valid starting points
           
                int next=x+1;
                int len=1;
                while(s.count(next)!=0){
                    next++;
                    len++;
                }
             maxlen=max(maxlen,len);
            }
             return maxlen;
        }
    
};