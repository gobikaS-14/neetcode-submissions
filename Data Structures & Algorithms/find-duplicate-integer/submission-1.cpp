
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;  // map to store seen numbers
        
        for (int num : nums) {
            mp[num]++;  
            if (mp[num]>1) {          // if number already seen
                return num;         // duplicate found
            }
                   
        }
        
        return -1;  // just in case, though problem guarantees a duplicate
    }
};