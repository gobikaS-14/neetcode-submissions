class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
// Iterate through the array, considering each element as the first element of the triplet
        vector<vector<int>> res;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++){
// Skip duplicate values for i
//compare the current element nums[i] with the previous element nums[i-1].
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int left=i+1,right=n-1;
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    res.push_back({nums[i], nums[left], nums[right]});

                    // Skip duplicates for left pointer
                    while (left < right && nums[left] == nums[left + 1])
                        left++;

                    // Skip duplicates for right pointer
                    while (left < right && nums[right] == nums[right - 1])
                        right--;

                    left++;
                    right--;
                }
                else if (sum < 0) {
                    left++;   // Need a bigger sum
                }
                else {
                    right--;  // Need a smaller sum
                }
            }

            }
            return res;
        }
    
};
