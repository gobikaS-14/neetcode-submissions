/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i+=2){
            if(nums[i]!=nums[i+1])  return nums[i];
        }
        return nums[nums.size()-1];//if last element is a single element
    }
};
*/

/*
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(nums[j]==nums[i])  count++;
            }
            if(count==1)    return nums[i];
        }
    return 0;
    }
};   */

//exor
//a ^ a = 0
//a ^ 0 = a
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;//// maybe contains garbage value like 12345 
        for(int i=0;i<nums.size();i++){
            res^=nums[i];
        }
        return res;
    }
};   
