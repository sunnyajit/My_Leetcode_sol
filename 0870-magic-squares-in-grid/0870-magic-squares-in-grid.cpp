 class Solution {
public: // code wriiten by sunny...
bool isMagicSquare(const vector<vector<int>>& grid) {
    vector<vector<vector<int>>> magicSquares = {
        {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
        {{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
        {{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
        {{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
        {{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
        {{4, 3, 8}, {9, 5, 1}, {2, 7, 6}},
        {{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
        {{2, 7, 6}, {9, 5, 1}, {4, 3, 8}}
    };

    for (const auto& magic : magicSquares) {
        bool isMagic = true;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (grid[i][j] != magic[i][j]) {
                    isMagic = false;
                    break;
                }
            }
            if (!isMagic) break;
        }
        if (isMagic) return true;
    }
    return false;
}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    int count = 0;
    if (row < 3 || col < 3) return 0;
    for (int i = 0; i <= row - 3; ++i) {
        for (int j = 0; j <= col - 3; ++j) {
            vector<vector<int>> subgrid(3, vector<int>(3));
            for (int x = 0; x < 3; ++x) {
                for (int y = 0; y < 3; ++y) {
                    subgrid[x][y] = grid[i + x][j + y];
                }
            }
            if (isMagicSquare(subgrid)) {
                ++count;
            }
        }
    }
    return count;
    }
};