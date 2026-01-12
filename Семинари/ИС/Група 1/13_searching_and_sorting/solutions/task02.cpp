class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(
            intervals.begin(), intervals.end(), [](
                const vector<int>& lhs, const vector<int>& rhs
            ) {
                return lhs[0] < rhs[0] || lhs[0] == rhs[0] && lhs[1] < rhs[1];
            });

        vector<vector<int>> result;
        int currentBegin = intervals[0][0];
        int currentEnd = intervals[0][1];

        for (size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= currentEnd) {
                currentEnd = max(intervals[i][1], currentEnd);
            }
            else {
                result.push_back({currentBegin, currentEnd});
                currentBegin = intervals[i][0];
                currentEnd = intervals[i][1];
            }
        }
        result.push_back({currentBegin, currentEnd});

        return result;
    }
};
