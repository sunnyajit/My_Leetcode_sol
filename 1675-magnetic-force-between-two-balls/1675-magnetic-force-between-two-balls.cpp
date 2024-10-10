 class Solution {
public: // Code written by sunny......
    bool canPlaceBalls(const vector<int>& position, int m, int min_force) {
    int count = 1;  
    int last_position = position[0];  

    for (int i = 1; i < position.size(); ++i) {
        if (position[i] - last_position >= min_force) {
            count++;
            last_position = position[i];
        }
        if (count >= m) return true;  
    }
    return false;  
}

int maxDistance(vector<int>& position, int m) {
    sort(position.begin(), position.end());  

    int left = 1;  
    int right = position.back() - position.front();  

    int result = 0;

    
    while (left <= right) {
        int mid = left + (right - left) / 2;  

        if (canPlaceBalls(position, m, mid)) {
            result = mid;   
            left = mid + 1;  
        } else {
            right = mid - 1;  
        }
    }

    return result;  
}

int main() {
    vector<int> position1 = {1, 2, 3, 4, 7};
    int m1 = 3;
    cout << "Example 1: " << maxDistance(position1, m1) << endl;

    vector<int> position2 = {5, 4, 3, 2, 1, 1000000000};
    int m2 = 2;
    cout << "Example 2: " << maxDistance(position2, m2) << endl;

    return 0;
 }
};