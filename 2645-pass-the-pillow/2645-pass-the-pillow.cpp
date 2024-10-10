 class Solution {
public: // code written by sunny..
    int passThePillow(int n, int time) {
    int pos = 1;
    int direction = 1;  
    while (time > 0) {
        pos += direction;
        if (pos == n) {
            direction = -1;
        } else if (pos == 1) {
            direction = 1;
        }
        time--;
    }
    return pos;
}
int main() {
    int n, time;
    std::cin >> n >> time;
    std::cout << passThePillow(n, time) << std::endl;
    return 0;
    }
};