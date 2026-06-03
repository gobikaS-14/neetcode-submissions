class Solution {
public:
    int trap(vector<int>& arr) {
        int l=0,r=arr.size()-1;
        int lmax=0,rmax=0;
        int tot=0;
        while(l<r){
        //if leftmax is lesser than or equal rightmax
        if(arr[l]<=arr[r]){
            //rain trapped
            if(arr[l]<lmax) tot+=lmax-arr[l];
            else lmax=arr[l];
            l++;
        }
        //if rmax is lesser than lmax
        else{
            //rain trapped
            if(arr[r]<rmax) tot+=rmax-arr[r];
            else rmax=arr[r];
            r--;
        }
        }
        return tot;

    }
};
