class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n=grid.size();
       int m=grid[0].size();
       queue<pair<int,int>> q;

       int dr[4] = {-1, 1, 0, 0};
       int dc[4] = {0, 0, -1, 1};
       int minutes =-1;
       int fresh=0; 

       for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==2)   q.push({i,j});
            else if (grid[i][j] == 1) fresh++;
        }
       }
       if(fresh==0) return 0;//if grid=[[0]]

       while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){ 
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr >= 0 && nr < n &&nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;//visited and rotted
                        fresh--;
                        q.push({nr,nc});
                    }
                }
           }
           minutes++;
       }
       return (fresh==0)? minutes:-1;
    }
};