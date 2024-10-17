class Solution {
public: // code writte by sunny
    int finalPositionOfSnake(int n, vector<string>& commands) {
    int row = 0;
    int col = 0;
    for (const auto& command : commands) {
        if (command == "UP") {
            row--;
        } else if (command == "DOWN") {
            row++;
        } else if (command == "LEFT") {
            col--;
        } else if (command == "RIGHT") {
            col++;
        }
    }
    return row * n + col;
    }
};