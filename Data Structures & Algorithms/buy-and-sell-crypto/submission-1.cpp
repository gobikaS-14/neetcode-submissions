class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n < 2) return 0;

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
};


/*
class Solution {
    public int maxProfit(int[] nums) {
        int n=nums.length;
        int maxp=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int max=nums[j]-nums[i];
                if(maxp<max)
                    maxp=max;
            }
        }
        return maxp;


        
        
    }
}*/