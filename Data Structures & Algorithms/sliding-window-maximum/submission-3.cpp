/*brute force
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<=n-k;i++){
            int maxi=INT_MIN;
            for(int j=i;j<i+k;j++){
                if(nums[j]>maxi) maxi=nums[j];
            }
            res.push_back(maxi);
        }
        return res;
    }
};
*/



class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        deque<int> dq;   // stores indices

        for (int i = 0; i < n; i++) {

            // 1️⃣ Remove elements out of current window
            if (!dq.empty() && dq.front() < i-k+1) {
                dq.pop_front();
            }

            // 2️⃣ Remove smaller elements from back
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }

            // 3️⃣ Push current index
            dq.push_back(i);

            // 4️⃣ Add max for window
            if (i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
