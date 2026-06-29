class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int steps=0;
        
        for(int i=0;i<n;i++){
            if(steps>=n-1)  return true;

            else{
                int max_indx=INT_MIN;
                for(int j=1;j<=nums[i];j++){
                    int indx=i+j;
                    max_indx=max(indx,max_indx);
                }
                steps=max_indx;
            }
        }
        return false;
    }
};
