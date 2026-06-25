class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int max_pro=0;
        int profit;
        int n=arr.size();
        for(int i=0;i<=n-2;i++){//buy
            for(int j=i+1;j<=n-1;j++){//sell
                if(arr[i]<arr[j]){
                profit =arr[j]-arr[i];
                max_pro = max(max_pro,profit);
                }
        }
        }
        return max_pro;
    }
};
