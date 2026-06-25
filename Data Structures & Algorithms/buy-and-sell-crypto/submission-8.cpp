class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int max_pro=0;
        int buy=0,sell=1;
        while(sell<n){
            if(arr[sell]>arr[buy]) {
                int profit=arr[sell]-arr[buy];
                max_pro=max(max_pro,profit);
                
            }
            else buy=sell;
            sell++;
        }
        return max_pro;
    }
};
