/*class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]+nums[j]==target){
                    return{i,j};
                }
            }
        }
        return {};
    }
};*/

//optimal
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> mp;
        //number → index
        for(int i=0;i<n;i++){
            int complement=target-nums[i];
            //count(key) returns 1 if the key exists, else 0.
            if(mp.count(complement)){
                return {mp[complement],i};
            }
            
        mp[nums[i]] = i;

        }
    return {};
    }
};        

        
                
