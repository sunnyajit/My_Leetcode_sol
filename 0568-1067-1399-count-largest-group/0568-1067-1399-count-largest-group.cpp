#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public: // code written by sunny
    int countLargestGroup(int n) {
        unordered_map<int, int> digitSumGroups;
        int maxSize = 0;

        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            digitSumGroups[sum]++;
            maxSize = max(maxSize, digitSumGroups[sum]);
        }

        int count = 0;
        for (auto& [sum, size] : digitSumGroups) {
            if (size == maxSize)
                count++;
        }
        return count;
    }

private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
