class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> scoresStack;
        int score = 0; // Показва ни какво имаме дотук.
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') {
                scoresStack.push(score);
                score = 0;
            }
            else {
                score = scoresStack.top() + max(2 * score, 1);
                scoresStack.pop();
            }
        }
        return score;
    }
};
