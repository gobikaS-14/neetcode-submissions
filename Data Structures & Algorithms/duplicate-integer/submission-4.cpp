//brute force
/*class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==nums[i+1])
                return true;
        }
        return false;
        
    }
};*/

//optimal
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> set;
        for(int i=0;i<n;i++){
            //returns 1 (element is present)
            if(set.count(nums[i])) return true;
            set.insert(nums[i]);
        }
        return false;

    }
};        
