//C++

class Solution {
public:
    int maxEdgesToAdd(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        vector<int> indegree(V, 0);

        // Build adjacency list and indegree array
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        // Topological sort (Kahn’s Algorithm)
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (int nei : adj[node]) {
                indegree[nei]--;
                if (indegree[nei] == 0)
                    q.push(nei);
            }
        }

        // Create a matrix to mark existing edges
        vector<vector<bool>> hasEdge(V, vector<bool>(V, false));
        for (auto &e : edges) {
            hasEdge[e[0]][e[1]] = true;
        }

        int count = 0;

        // In a DAG, edge u->v is valid only if u comes before v in topological order
        // So we can safely add edges from earlier nodes to later nodes (if not already present)
        for (int i = 0; i < V; i++) {
            for (int j = i + 1; j < V; j++) {
                int u = topo[i];
                int v = topo[j];
                if (!hasEdge[u][v])
                    count++;
            }
        }

        return count;
    }
};
