class Solution {
public:
    struct NodeToVisit {
        int idx;
        bool shouldColor;
    };

    bool isBipartite(vector<vector<int>>& graph) {
        size_t nNodes = graph.size();
        vector<bool> visited(nNodes, false);
        vector<bool> colored(nNodes, false);

        for (int i = 0; i < nNodes; ++i) {
            if (visited[i]) continue;

            queue<NodeToVisit> toVisit;
            toVisit.push({.idx{i}, .shouldColor{false}});

            while (!toVisit.empty()) {
                NodeToVisit current = toVisit.front();
                toVisit.pop();

                if (!visited[current.idx]) {
                    visited[current.idx] = true;
                    colored[current.idx] = current.shouldColor;

                    for (int neighbor : graph[current.idx]) {
                        toVisit.push({.idx{neighbor}, .shouldColor{!current.shouldColor}});
                    }
                }
                else if (colored[current.idx] != current.shouldColor) {
                    return false;
                }
            }
        }

        return true;
    }
};
