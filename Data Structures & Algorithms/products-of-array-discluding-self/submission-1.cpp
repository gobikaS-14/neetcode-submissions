//brute force-o(n^2)
/*
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int mul=1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    mul*=nums[j];
                }
            }
            res.push_back(mul);
        }
        return res;
    }
};
*/

//optimal
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> res;
       // res = prefix product * suffix product
        //prefix product
        int prefix=1;
        for(int i=0;i<n;i++){
            res.push_back(prefix);
            prefix*=nums[i];
        }

        //suffix product
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            res[i]*=suffix;
            suffix*=nums[i];
        }
        return res;
    }
}; 