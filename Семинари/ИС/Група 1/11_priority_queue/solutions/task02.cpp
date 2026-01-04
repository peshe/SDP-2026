class Solution {
    // cost, index of vertex
    typedef pair<int, size_t> Cost;

    int manhattanDistance(const vector<int>& pointA, const vector<int>& pointB) {
        return abs(pointA[0] - pointB[0]) + abs(pointA[1] - pointB[1]);
    }

public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        size_t nPoints = points.size();
        vector<bool> explored(nPoints, false);
        vector<int> lowestCosts(nPoints, numeric_limits<int>::max());

        priority_queue<Cost, vector<Cost>, greater<Cost>> lowestCostsQ;
        lowestCostsQ.push(make_pair(0, 0));
        lowestCosts[0] = 0;

        while (!lowestCostsQ.empty()) {
            Cost currentVertex = lowestCostsQ.top();
            lowestCostsQ.pop();

            if (explored[currentVertex.second]) continue;
            explored[currentVertex.second] = true;

            for (size_t neighbor = 0; neighbor < nPoints; ++neighbor) {
                if (explored[neighbor]) continue;

                int newCost = manhattanDistance(points[currentVertex.second], points[neighbor]);

                if (newCost < lowestCosts[neighbor]) {
                    lowestCosts[neighbor] = newCost;
                    lowestCostsQ.push(make_pair(newCost, neighbor));
                }
            }
        }

        int totalLowestCost = 0;
        for (int cost : lowestCosts) {
            totalLowestCost += cost;
        }
        return totalLowestCost;
    }
};
