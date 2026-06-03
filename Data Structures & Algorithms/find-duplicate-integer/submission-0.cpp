
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, bool> mp;  // map to store seen numbers
        
        for (int num : nums) {
            if (mp[num]) {          // if number already seen
                return num;         // duplicate found
            }
            mp[num] = true;         // mark number as seen
        }
        
        return -1;  // just in case, though problem guarantees a duplicate
    }
};