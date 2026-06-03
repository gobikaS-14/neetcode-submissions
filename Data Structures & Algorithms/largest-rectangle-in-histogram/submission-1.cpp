class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n=h.size();
        int maxArea=INT_MIN;
        for(int i=0;i<n;i++){
            int mini=h[i];
            for(int j=i;j<n;j++){
                mini=min(mini,h[j]);
                int width=j-i+1;//no of bars in a selected group
                int area=mini *width;
                maxArea=max(maxArea,area);
            }
        }
        return maxArea;
    }
};
