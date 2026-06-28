class Solution {
public:
    int ladderLength(string begin, string end, vector<string>& word) {


        queue<pair<string,int>> q;
        unordered_set<string> set(word.begin(),word.end());
        q.push({begin,1});
        if (!set.count(end))
            return 0;
    
        //bfs
        while(!q.empty()){
            auto[node,l]=q.front();
            q.pop();
            if(node==end) return l;
            for(int i=0;i<node.size();i++){
                string temp=node;
                for(char c='a';c<='z';c++){
                    if (c == node[i]) continue;
                    temp[i]=c;
                    if(set.count(temp)){
                        set.erase(temp);
                        q.push({temp,l+1});
                    }
                }
            }
        }
        
    }
};
