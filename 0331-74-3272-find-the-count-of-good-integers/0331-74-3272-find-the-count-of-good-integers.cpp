class Solution {
public: // code written by sunny
    long long countGoodIntegers(int n, int k) {
        unordered_set<string> s;
        int d = (n + 1) / 2, a = pow(10, d - 1), b = pow(10, d);

        for (int i = a; i < b; ++i) {
            string l = to_string(i), r = l;
            if (n % 2) r.pop_back();
            reverse(r.begin(), r.end());
            string p = l + r;
            if (stoll(p) % k) continue;
            sort(p.begin(), p.end());
            s.insert(p);
        }

        vector<long long> f(11, 1);
        for (int i = 1; i < 11; ++i) f[i] = f[i - 1] * i;

        long long res = 0;
        for (auto& x : s) {
            vector<int> c(10);
            for (char ch : x) c[ch - '0']++;
            int len = x.size(), z = c[0];
            long long p = (len - z) * f[len - 1];
            for (int v : c) p /= f[v];
            res += p;
        }
        return res;
    }
};
