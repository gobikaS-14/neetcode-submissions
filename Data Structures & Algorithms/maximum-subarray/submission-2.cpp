
//Greedy(kadane-o(n))
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=INT_MIN;
        int sum=0;
        if(nums.size()==1)    return nums[0];
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum<0)   sum=0;
            max_sum=max(sum,max_sum);
        }
        return max_sum;
    }
};
