class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res(n-k+1);
        for(int i=0;i<=n-k;i++){
            int maxi=INT_MIN;
            for(int j=i;j<i+k;j++){
                if(nums[j]>maxi) maxi=nums[j];
            }
            res[i]=maxi;
        }
        return res;
    }
};
