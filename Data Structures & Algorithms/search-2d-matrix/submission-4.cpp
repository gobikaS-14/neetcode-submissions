class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int x) {
        int m=mat.size(),n=mat[0].size();
        int r=0,c=n-1; 

        while(r<m && c>=0){

            if(mat[r][c]==x)    return true;

            else if(mat[r][c]<x) r++;

            else    c--;
        }
        return false;
    }
};
