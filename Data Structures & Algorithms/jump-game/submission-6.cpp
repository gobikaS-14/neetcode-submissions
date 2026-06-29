class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            if(i+nums[i]>=n-1)  return true;
            i=i+nums[i];
            if(i==i+nums[i])    return false;
        }
        return false;
    }
};
