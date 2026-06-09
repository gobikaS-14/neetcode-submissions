class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int m_area=0; // added

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        queue<pair<int,int>>q;
        vector<vector<int>> v(n, vector<int>(m, 0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && v[i][j]==0){
                    q.push({i,j});
                    v[i][j]=1;

                    int area=1; //added
                    while(!q.empty()){
                        int r =q.front().first;
                        int c=q.front().second;
                        q.pop();
                        for(int k = 0; k < 4; k++) {
                            int nr = r + dr[k];
                            int nc = c + dc[k];
                            if((nr>=0 && nr<n && nc>=0 && nc<m) &&
                                (v[nr][nc]==0) &&
                                (grid[nr][nc]==1)) {
                                area++; //added
                                v[nr][nc]=1; 
                                q.push({nr,nc}); 
                            }
                        }    
                    }
                    m_area=max(area,m_area);//added
                }
            }
        }
        return m_area;//added
    }
};
