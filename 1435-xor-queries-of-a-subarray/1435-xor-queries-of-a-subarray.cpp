 class Solution {
public: // code written by sunny
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
         int n = arr.size();
    int q = queries.size();
    vector<int> prefixXOR(n);
    prefixXOR[0] = arr[0];
    
    for (int i = 1; i < n; ++i) {
        prefixXOR[i] = prefixXOR[i - 1] ^ arr[i];
    }
    vector<int> result(q);
    for (int i = 0; i < q; ++i) {
        int left = queries[i][0];
        int right = queries[i][1];
        if (left == 0) {
            result[i] = prefixXOR[right];
        } else {
            result[i] = prefixXOR[right] ^ prefixXOR[left - 1];
        }
    }
    
    return result;
    }
};