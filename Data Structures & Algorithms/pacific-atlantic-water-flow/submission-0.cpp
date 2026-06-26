//https://youtu.be/krL3r7MY7Dc
class Solution {
public:
    void bfs(vector<vector<int>>& grid,int n,int m,vector<vector<bool>> &Ocean,queue<pair<int,int>> &q){
        int dr[]={-1,1,0,0};
        int dc[]={0,0,-1,1};

        //bfs
        while(!q.empty()){
            auto [r,c]=q.front();
            q.pop();
            for(int k=0;k<4;k++){

                int nr= r+dr[k];
                int nc=c+dc[k];
                if(nr >= 0 && nr < n &&nc >= 0 && nc < m && !Ocean[nr][nc] && grid[nr][nc]>=grid[r][c]){
                    Ocean[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
         }

    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> res;
        vector<vector<bool>> P(n,vector<bool>(m,false));
        vector<vector<bool>> A(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
    //pacific Ocean sources
        //left border cells
        for(int i=0;i<n;i++){
            P[i][0]=1;
            q.push({i,0});
        }
        //top border cells
        for(int i=0;i<m;i++){
            P[0][i]=1;
            q.push({0,i});
        }
        //bfs for Pacific
        bfs(grid,n,m,P,q);

        //Atlantic Ocean sources
        //right border cells
        for(int i=0;i<n;i++){
            A[i][m-1]=1;
            q.push({i,m-1});
        }
        //bottom border cells
        for(int i=0;i<m;i++){
            A[n-1][i]=1;
            q.push({n-1,i});
        }
        //bfs for atlantic
        bfs(grid,n,m,A,q);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(P[i][j] && A[i][j])  res.push_back({i,j});
            }
        }
        return res;
    }
};
