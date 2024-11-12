class Solution {
public: // code written by sunny
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
         sort(items.begin(), items.end());
        vector<pair<int, int>> price_beauty; 
        int max_beauty = 0;
        
        for (auto& item : items) {
            int price = item[0];
            int beauty = item[1];
            max_beauty = max(max_beauty, beauty);  
            price_beauty.push_back({price, max_beauty}); 
        }
        int q = queries.size();
        vector<int> answer(q);
        vector<pair<int, int>> sorted_queries;
        
        for (int i = 0; i < q; ++i) {
            sorted_queries.push_back({queries[i], i});
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        int j = 0;  
        for (auto& query : sorted_queries) {
            int query_price = query.first;
            int index = query.second;
            while (j < price_beauty.size() && price_beauty[j].first <= query_price) {
                ++j;
            }
            if (j > 0) {
                answer[index] = price_beauty[j - 1].second;
            } else {
                answer[index] = 0;  
            }
        }
        
        return answer;
    }
};