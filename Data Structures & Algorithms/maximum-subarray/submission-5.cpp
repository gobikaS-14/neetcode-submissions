/*Brute force mindset:
    “Try all subarrays”
Kadane mindset:
    “At each index, I only care about the best subarray ending here
*/
//Greedy(kadane-o(n))
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int max_sum=INT_MIN;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            max_sum=max(sum,max_sum);
            if(sum<0)   sum=0;//A negative running sum will NEVER help future elements
            //local irreversible decision-greedy
        }
        return max_sum;
    }
};
