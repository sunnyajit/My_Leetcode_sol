class Solution {
public:// code written by sunny
    class FenwickTree {
        vector<int> bit;
        int n;
    public:
        FenwickTree(int size) : n(size), bit(size + 1, 0) {}

        void update(int index, int val) {
            index++;
            while (index <= n) {
                bit[index] += val;
                index += index & -index;
            }
        }

        int query(int index) {
            index++;
            int sum = 0;
            while (index > 0) {
                sum += bit[index];
                index -= index & -index;
            }
            return sum;
        }
    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> pos_in_nums2(n);
        for (int i = 0; i < n; ++i) {
            pos_in_nums2[nums2[i]] = i;
        }

        vector<int> index(n);
        for (int i = 0; i < n; ++i) {
            index[i] = pos_in_nums2[nums1[i]];
        }

        vector<long long> left_smaller(n, 0);
        FenwickTree bit1(n);
        for (int i = 0; i < n; ++i) {
            left_smaller[i] = bit1.query(index[i] - 1);
            bit1.update(index[i], 1);
        }

        vector<long long> right_larger(n, 0);
        FenwickTree bit2(n);
        for (int i = n - 1; i >= 0; --i) {
            right_larger[i] = bit2.query(n - 1) - bit2.query(index[i]);
            bit2.update(index[i], 1);
        }

        long long total = 0;
        for (int i = 0; i < n; ++i) {
            total += left_smaller[i] * right_larger[i];
        }

        return total;
    }
};
