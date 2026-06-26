class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1) //n = 1 edges = [[0,0]]
            return false;

        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //bfs
        queue<pair<int,int>>q;
        vector<int> v(n, 0);
        q.push({0,0});
        v[0]=1;

        while(!q.empty()){
            int curr=q.front().first;
            int parent=q.front().second;
            q.pop();

            for(int neigh:adj[curr]){//neighs
                if(v[neigh] &&  neigh!=parent){
                    return false;//1.cycle exists
                }
                else if(v[neigh]==0) {
                v[neigh]=1;
                q.push({neigh,curr});
                }
                
            }
        }
        //2.check for all nodes are  visited(connectivity)
        for (int i : v) {
            if (!i) return false;
        }

        return true;
    }
};
