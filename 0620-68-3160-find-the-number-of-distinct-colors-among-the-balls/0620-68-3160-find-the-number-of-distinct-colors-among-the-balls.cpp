#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
// code written by sunny
class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        vector<int> result;
        unordered_map<int, int> ball_colors; 
        unordered_map<int, int> color_count; 
        
        for (const auto& query : queries) {
            int ball = query[0];
            int color = query[1]; 
            if (ball_colors.find(ball) != ball_colors.end()) {
                int old_color = ball_colors[ball];
                color_count[old_color]--;
                if (color_count[old_color] == 0) {
                    color_count.erase(old_color);
                }
            } 
            ball_colors[ball] = color;
            
            // Add the new color to the color count
            color_count[color]++; 
            result.push_back(color_count.size());
        }
        
        return result;
    }
};
