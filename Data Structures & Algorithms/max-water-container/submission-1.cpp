//brute froce
/*class Solution {
public:
    int maxArea(vector<int>& arr) {
        int maxA=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int h=min(arr[i],arr[j]);
                int w=j-i;
                int area=h*w;
                maxA=max(maxA,area);
            }
        }
        return maxA;
        
    }
};
*/

//optimal
class Solution {
public:
    int maxArea(vector<int>& arr) {
        int maxA=0;
        int n=arr.size();
        int l=0,r=n-1;
        while(l<r){
            int h=min(arr[l],arr[r]);
            int w=r-l;
            int area=h*w;
            maxA=max(maxA,area);

            if(arr[l]<arr[r]) l++;
            else r--;
        }
        return maxA;
            
    }
};        
