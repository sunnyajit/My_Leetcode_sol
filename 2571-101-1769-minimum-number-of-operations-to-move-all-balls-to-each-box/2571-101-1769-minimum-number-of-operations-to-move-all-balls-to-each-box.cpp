class Solution {
public: // code written by sunny
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int> answer(n, 0);
        
        int balls = 0, operations = 0;
        for (int i = 0; i < n; ++i) {
            answer[i] += operations;
            balls += (boxes[i] == '1');
            operations += balls;
        }
        
        balls = 0;
        operations = 0;
        for (int i = n - 1; i >= 0; --i) {
            answer[i] += operations;
            balls += (boxes[i] == '1');
            operations += balls;
        }
        
        return answer;
    }
};
