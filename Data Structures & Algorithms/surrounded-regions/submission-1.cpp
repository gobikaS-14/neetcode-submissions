class Solution {
public:
    void solve(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;

        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((j==0 || i==0 || j==m-1||i==n-1 ) && grid[i][j]=='O'){
                    q.push({i,j});
                    grid[i][j]='#';
                    while(!q.empty()){
                        auto[r,c]=q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nr= r+dr[k];
                            int nc=c+dc[k];
                            if(nr >= 0 && nr < n &&nc >= 0 && nc < m &&grid[nr][nc]=='O'){
                                grid[nr][nc]='#';
                                q.push({nr,nc});
                    
                            }
                        }                  
                    }
                }
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){    
                if(grid[i][j]=='#') grid[i][j]='O';
                else grid[i][j]='X';
            }
        }   
        
    }
};
