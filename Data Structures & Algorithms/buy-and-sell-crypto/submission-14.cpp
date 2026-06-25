class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxPrice = INT_MIN;
        int maxProfit = 0;
        int n=arr.size();
        int sell=n-1;
        
        for (int buy=n-2;buy>=0;buy--) {
            maxPrice = max(maxPrice, arr[sell]);
            maxProfit = max(maxProfit,  maxPrice-arr[buy]);
            sell--;
        }

        return maxProfit;
    }
};
/*At each index i:

You are asking:

“If I buy today, what is the best future sell price?”*/