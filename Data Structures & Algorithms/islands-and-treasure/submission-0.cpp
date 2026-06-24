class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)   q.push({i,j});
            }
        }

        while(!q.empty()){
            int size=q.size();
            for(int s=0;s<size;s++){
                auto[r,c]=q.front();//parent (curr node at level n)
                q.pop();
            for (int k = 0; k < 4; k++) {//childs(neigh at next level of parent)
                int nr = r + dr[k];
                int nc = c + dc[k];

                if(nr >= 0 && nr < n &&nc >= 0 && nc < m && grid[nr][nc] ==2147483647) {
                    grid[nr][nc]= grid[r][c]+1;
                    q.push({nr,nc});
                }            
            }
        }
    }
}
};
