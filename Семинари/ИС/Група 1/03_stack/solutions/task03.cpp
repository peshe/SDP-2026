class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int poppedCount = 0;

        for (int p : pushed) {
          s.push(p);

          while (!s.empty() && s.top() == popped[poppedCount]) {
              poppedCount++;
              s.pop();
          }
        }
        return s.empty() && poppedCount == popped.size();
    }
};
