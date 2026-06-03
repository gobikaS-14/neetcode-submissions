class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int mul=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    mul*=nums[j];
                }
            }
            res.push_back(mul);
        }
        return res;
    }
};
