/*brute force
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0;
        // For each possible buy index i
        for (int i = 0; i < n - 1; ++i) {
            // For each possible sell index j after i
            for (int j = i + 1; j < n; ++j) {
                int profit = prices[j] - prices[i];
                if (profit > maxProfit) maxProfit = profit;
            }
        }
        return maxProfit;
    }
};*/


//optimal-sliding window
class Solution {
    public:
     int maxProfit(vector<int>& nums) {
        int n= nums.size();
        int l=0;//buy pointer
        int r=1;//sell pointer
        int maxprofit=0;
        while(r<n){
            //Moves r through the array (future sell days)
            //Keeps adjusting l to always be the lowest possible buy price
            if(nums[r]>nums[l]){
                int profit=nums[r]-nums[l];
                maxprofit= max(maxprofit,profit);
            }
            else l=r;
            r++;//always increment r
        }
       return maxprofit;        
    }
};