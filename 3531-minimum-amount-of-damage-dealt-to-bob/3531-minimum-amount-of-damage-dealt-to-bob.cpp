class Solution {
public: // code written by sunny
    long long minDamage(int power, vector<int>& damage, vector<int>& health) {
    int n = damage.size();
    vector<pair<int, int>> enemies;
    for (int i = 0; i < n; ++i) {
        enemies.push_back({damage[i], health[i]});
    }
    sort(enemies.begin(), enemies.end(), [power](pair<int, int>& a, pair<int, int>& b) {
        long long valueA = (long long)(b.second + power - 1) / power;
        long long valueB = (long long)(a.second + power - 1) / power;
        return valueA * a.first > valueB * b.first;
    });
    long long totalDamage = 0;
    long long currentDamage = 0;
    for (auto& enemy : enemies) {
        currentDamage += enemy.first;
    }
    for (auto& enemy : enemies) {
        int hits = (enemy.second + power - 1) / power; 
        totalDamage += hits * currentDamage;
        currentDamage -= enemy.first;  
    }
    return totalDamage;
    }
};