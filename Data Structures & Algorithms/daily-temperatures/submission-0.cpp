class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n= arr.size();
        vector<int>res(n,0);
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n){
                if(arr[j]<=arr[i]) j++;
                else{
                    res[i]=j-i;
                    break;
                }

            }
        }
        return res;
    }
};
