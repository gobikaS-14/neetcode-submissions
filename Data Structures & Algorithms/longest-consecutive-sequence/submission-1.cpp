class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0,j;
        for(int i=0;i<n;i++){
            int x=nums[i];
            int flag=1;
            int len=1;
            int next=x+1;
            while(flag==1){
                int found=0;
                for(j=0;j<n;j++){
                    if(nums[j]==next){
                        found=1;
                        len+=1;
                        next++;
                        break;
                    }
                }
                if(found==1) flag=1;
                else flag=0;
            }
            maxlen=max(maxlen,len);
        }
        return maxlen;
    }
};
