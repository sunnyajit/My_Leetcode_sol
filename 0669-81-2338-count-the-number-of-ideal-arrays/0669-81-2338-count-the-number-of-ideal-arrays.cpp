class Solution {
public: // code written by sunny
    const int MOD = 1e9 + 7;
    int MAXN;
    vector<long long> fact, invFact;

    long long power(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    void precomputeFactorials(int n) {
        MAXN = n + 10;
        fact.resize(MAXN);
        invFact.resize(MAXN);
        fact[0] = 1;
        for (int i = 1; i < MAXN; ++i)
            fact[i] = fact[i - 1] * i % MOD;
        invFact[MAXN - 1] = power(fact[MAXN - 1], MOD - 2);
        for (int i = MAXN - 2; i >= 0; --i)
            invFact[i] = invFact[i + 1] * (i + 1) % MOD;
    }

    long long comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] % MOD * invFact[n - k] % MOD;
    }

    int idealArrays(int n, int maxValue) {
        precomputeFactorials(n + 100);

        int maxLen = 14; // log2(10^4) ≈ 14 → max length of any chain
        vector<vector<long long>> dp(maxLen + 1, vector<long long>(maxValue + 1, 0));

        // Base case: length = 1 → every number from 1 to maxValue is valid
        for (int i = 1; i <= maxValue; ++i)
            dp[1][i] = 1;

        for (int len = 2; len <= maxLen; ++len) {
            for (int i = 1; i <= maxValue; ++i) {
                for (int j = 2 * i; j <= maxValue; j += i) {
                    dp[len][j] = (dp[len][j] + dp[len - 1][i]) % MOD;
                }
            }
        }

        long long res = 0;
        for (int len = 1; len <= maxLen; ++len) {
            for (int val = 1; val <= maxValue; ++val) {
                if (dp[len][val] > 0) {
                    res = (res + dp[len][val] * comb(n - 1, len - 1) % MOD) % MOD;
                }
            }
        }

        return (int)res;
    }
};
