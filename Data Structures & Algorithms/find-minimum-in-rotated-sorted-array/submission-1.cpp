class Solution {
public:
    int findMin(vector<int> &arr) {
        int n=arr.size();
        int i;
        for(i=0;i<n-1;i++){
            if(arr[i]>arr[i+1]){
                break;
            }
        }
        if(i==n-1) return arr[0];
        return arr[i+1];
    }
};
