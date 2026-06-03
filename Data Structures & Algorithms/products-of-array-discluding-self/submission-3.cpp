class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        int prefix=1;
        for(int i=0;i<n;i++){
            res.push_back(prefix);
            prefix=prefix*nums[i];
        }
        
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=suffix;
            suffix*=nums[i];
        }
        return res;
    }
};
