 class Solution {
public: // code written by sunny
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
          int n = workerTimes.size();
    long long left = 0, right = 1e18;
    while (left < right) {
        long long mid = left + (right - left) / 2;
        long long totalReduced = 0;
        for (int i = 0; i < n; i++) {
            long long timeLeft = mid;
            long long heightReduced = 0;
            long long unitTime = workerTimes[i];
            long long k = 1;
            while (timeLeft >= unitTime * k) {
                timeLeft -= unitTime * k;
                heightReduced += 1;
                k++;
                if (heightReduced >= mountainHeight) break;
            }
            totalReduced += heightReduced;
            if (totalReduced >= mountainHeight) break; 
        }
        if (totalReduced >= mountainHeight) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
    }
};