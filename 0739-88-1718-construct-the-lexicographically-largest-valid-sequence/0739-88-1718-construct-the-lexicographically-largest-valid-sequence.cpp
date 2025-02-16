class Solution {
public: // code written by sunny
    vector<int> constructDistancedSequence(int n) {
         vector<int> sequence(2 * n - 1, 0);
         vector<bool> used(n + 1, false);
        backtrack(sequence, used, n, 0);
        return sequence;
    }
    
    bool backtrack(vector<int>& sequence, vector<bool>& used, int n, int idx) {
        if (idx == sequence.size()) {
            return true;
        }

        if (sequence[idx] != 0) {
            return backtrack(sequence, used, n, idx + 1);
        }

        for (int i = n; i >= 2; --i) {
            if (!used[i]) {
                for (int j = idx + i; j < sequence.size(); ++j) {
                    if (sequence[j] == 0 && j == idx + i) {
                        sequence[idx] = i;
                        sequence[j] = i;
                        used[i] = true;
                        
                        if (backtrack(sequence, used, n, idx + 1)) {
                            return true;
                        }
                        
                        sequence[idx] = 0;
                        sequence[j] = 0;
                        used[i] = false;
                    }
                }
            }
        }

        if (!used[1]) {
            sequence[idx] = 1;
            used[1] = true;
            if (backtrack(sequence, used, n, idx + 1)) {
                return true;
            }
            sequence[idx] = 0;
            used[1] = false;
        }
        
        return false;
    }
};
