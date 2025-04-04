// code written by sunny
    class Solution {
         public:
           vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
               const int n = arr.size();
                   double l = 0.0;
                       double r = 1.0;

                           while (l < r) {
                                 const double m = (l + r) / 2.0;
                                       int fractionsNoGreaterThanM = 0;
                                             int p = 0;
                                                   int q = 1;

                                                         // For each index i, find the first index j s.t. arr[i] / arr[j] <= m,
                                                               // so fractionsNoGreaterThanM for index i will be n - j.
                                                                     for (int i = 0, j = 1; i < n; ++i) {
                                                                             while (j < n && arr[i] > m * arr[j])
                                                                                       ++j;
                                                                                               if (j == n)
                                                                                                         break;
                                                                                                                 fractionsNoGreaterThanM += n - j;
                                                                                                                         if (p * arr[j] < q * arr[i]) {
                                                                                                                                   p = arr[i];
                                                                                                                                             q = arr[j];
                                                                                                                                                     }
                                                                                                                                                           }

                                                                                                                                                                 if (fractionsNoGreaterThanM == k)
                                                                                                                                                                         return {p, q};
                                                                                                                                                                               if (fractionsNoGreaterThanM > k)
                                                                                                                                                                                       r = m;
                                                                                                                                                                                             else
                                                                                                                                                                                                     l = m;
                                                                                                                                                                                                         }

                                                                                                                                                                                                             throw;
                                                                                                                                                                                                               }
                                                                                                                                                                                                              };
   