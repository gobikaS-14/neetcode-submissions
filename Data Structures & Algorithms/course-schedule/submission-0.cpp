class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);
        for(auto e: prerequisites){
            int v=e[0];
            int u=e[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        //bfs
        while(!q.empty()){
            int n=q.front();
            q.pop();
            res.push_back(n);
            for(int neigh:adj[n]){
                indegree[neigh]--;
                if(indegree[neigh]==0){
                    q.push(neigh);
                }
            }
        }
        return res.size()==numCourses;
    }
};
