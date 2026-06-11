class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {

        vector<vector<int>> adj(n);

        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        queue<int> q;
        int count = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                count++;

                q.push(i);
                vis[i] = 1;

                while(!q.empty()) {

                    int node = q.front();
                    q.pop();

                    for(int neigh : adj[node]) {

                        if(!vis[neigh]) {

                            vis[neigh] = 1;
                            q.push(neigh);
                        }
                    }
                }
            }
        }

        return count;
    }
};