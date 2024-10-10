 class Solution {
public: // code written by sunny..
    int findTheWinner(int n, int k) {
        int winner = 0; // Josephus(1, k) = 0
    for (int i = 1; i <= n; ++i) {
        winner = (winner + k) % i;
    }
    return winner + 1; // Adjusting to 1-based indexing
}

int main() {
    // Test cases
    cout << findTheWinner(5, 2) << endl; // Output: 3
    cout << findTheWinner(6, 5) << endl; // Output: 1
    return 0;
    }
};