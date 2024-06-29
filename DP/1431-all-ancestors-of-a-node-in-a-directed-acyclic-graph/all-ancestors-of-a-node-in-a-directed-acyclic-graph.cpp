class Solution {
public:

    void DFS(int source,unordered_map<int,vector<int>>& adjList,int ancestor,vector<vector<int>>& result) {
        
        for(auto nbr:adjList[source]) {

            if(result[nbr].empty() || result[nbr].back() != ancestor) {
                result[nbr].push_back(ancestor);
                DFS(nbr,adjList,ancestor,result);
            }
        }
    }

    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> result(n);

        unordered_map<int,vector<int>> adjList ;

        for(vector<int> edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adjList[u].push_back(v);
        }

        for(int i = 0 ; i < n ; i++) {
            int anscestor = i ;
            DFS(i,adjList,i,result);
        }

        return result ;
    }
};